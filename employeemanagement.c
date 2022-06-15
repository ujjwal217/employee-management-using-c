// Employee Management using C :: Version 1.0
#include<stdio.h>
typedef struct{
	int d,m,y;
} Date; 

typedef struct{
	int empid;
	char name[51],mobile[11],designation[21];
	Date dob;
	float salary;
} Employee;


Employee e;
FILE *fp;

// A function to save new employee 
void addEmployee(){
		system("cls");
		printf("Employee ID : ");fflush(stdin);scanf("%d",&e.empid);
		printf("Name : ");fflush(stdin);gets(e.name);
		printf("Mobile : ");fflush(stdin);scanf("%s",&e.mobile);
		printf("Designation : ");fflush(stdin);gets(e.designation);
		printf("Date of Birth (dd/mm/yyyy) : ");fflush(stdin);
		scanf("%d%*c%d%*c%d",&e.dob.d,&e.dob.m,&e.dob.y); // using suppression character
		printf("Salary : ");scanf("%f",&e.salary);
		
		fseek(fp,0,SEEK_END); //send the file pointer to end of the file
		fwrite(&e,sizeof(e),1,fp);
		printf("Record has been saved\n");
		system("pause"); // pause the screen and show the message - Press any key to continue
}
void showAllEmployees(){
	system("cls");
	printf("List of employees\n");
	rewind(fp); // send the file pointer to top of the file
	printf("%5s %-20s %-10s %-15s %10s %10s\n","EmpID","Name","Mobile","Designation","DOB","Salary");
	while(fread(&e,sizeof(e),1,fp)){ // read the records one by one till end of file is reached
		printf("%5d %-20s %-10s %-15s %02d/%02d/%d %10.2f\n",e.empid,e.name,e.mobile,e.designation,e.dob.d,e.dob.m,e.dob.y,e.salary);
	}
	system("pause");	
}
void searchEmployee(){
	int empid,found=0;
	system("cls");
	printf("Employee ID to search : ");scanf("%d",&empid);
	rewind(fp); 
	while(fread(&e,sizeof(e),1,fp)){
		if(e.empid==empid){
			found=1;
			break;
		}
	}
	if(found)
		printf("Record found as %s %s %f\n",e.name,e.designation,e.salary);
	else
		printf("Sorry! No such record found\n");
	system("pause");
}
void updateEmployee(){
	
}
void deleteEmployee(){
	
}

main(){
	int choice;
	fp=fopen("empdata.bin","rb+"); // open the file for read and write in binary mode
	if(fp==NULL)
	 fp=fopen("empdata.bin","wb+"); // create the file and open in binary mode
	for(;;){
		system("cls");
		printf(">>>>>>> Main Menu <<<<<<<\n");
		printf("1 : Add Employee\n");
		printf("2 : Show All Employees\n");
		printf("3 : Search Employee\n");
		printf("4 : Update Employee\n");
		printf("5 : Delete Employee\n");
		printf("6 : Quit Application\n");
		printf("Enter choice : "); scanf("%d",&choice);
		switch(choice){
			case 1: addEmployee();break;
			case 2: showAllEmployees();break;
			case 3: searchEmployee();break;
			case 4: updateEmployee(); break;
			case 5: deleteEmployee();break;
			case 6: fclose(fp);exit(0); // close the file and quit the application
		}
		
	}
}



