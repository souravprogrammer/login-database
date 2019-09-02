/*    
       This program gives you an over view how Login system Database work.
       limitation of this program ;- 
       1.valid up to only one user. 

       -------------------------------------------------------------
       internet <souravsh1234567@gmail.com>
       -------------------------------------------------------------
 */


#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void login()
{
  system("clear") ;
  printf("congratlution you sccusfully logged in :) ") ; 
}

void main ()
{
  /*declaring a string  */
    char name[10] ,name_holder[10], password[10] ,password_holder[10]   ;
    int x ,y,z = 0;
    FILE *fp ; /*file pointer "fp" will carry the base address of username.txt file */
    FILE *fs ; /*file pointer  of "fs" will carry the base adress of password.txt file */
    printf("1 . creat account \n 2. log in \n >>") ;
    scanf("%d",&z) ;
    fflush(stdin) ;
    fflush(stdout) ;
if (z == 1) 
{
  /*in this condition username & password will save in file */
    fp = fopen("name.txt","w+") ;
    printf("enter name >> ") ;
    scanf("%s",&name) ;
    fflush(stdin) ;
    fflush(stdout) ;
    fprintf(fp,"%s\n",name) ; /*storing a string "name" in file called "name.txt"  */
    fclose(fp) ;
    printf("enter the new password >> ") ;
    scanf("%s",&password) ;
    fs = fopen ("password.txt","w+") ; /*storing a sting "password"in file called "password.txt" */
    fprintf(fs,"%s\n",password) ;
    fclose (fs) ;
}
if(z == 2)
{
  /*In this condition if you already save any username &password in a file it will cheak it with your 
  input with a saved result */
  printf("enter your username >> ");
  scanf("%s",&name) ;
  fflush(stdin) ;
    fflush(stdout) ;
  printf("password >>") ;
  scanf("%s",&password) ;
  fflush(stdin) ;
   fflush(stdout) ;

  fp = fopen("name.txt","r") ; /*opening a file called "name.txt"in read mode*/

    while(fscanf(fp,"%s",name_holder)!= EOF)
    {

    x = strcmp (name ,name_holder) ;/*If input result will match with the saved result in file  strcmp will return "0"*/
    if (x == 0 )
    {
      fclose(fp) ;/*closing file "name.txt" from buffer */
      fs = fopen("password.txt","r") ;
      while (fscanf(fs,"%s",password_holder) != EOF) 
{
       y = strcmp(password,password_holder) ;
       if (y == 0)
       {
        fclose(fs) ;
        login() ;
         break ;
       }
}
        
    }
    }
}

}
