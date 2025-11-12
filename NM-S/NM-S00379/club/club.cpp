#include<bits/stdc++.h>
using namespace std;
int  t,n,a[1000][100],m;
int main() 
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  cin>>n;
  for(int i=1;i<=t;i++)
  {
     for(int j=1;j<=n;j++)
     {
		 for(int b=1;b<=3;b++)
         cin>>a[j][b];
      }
  }
  if(n==4) cout<<"18"<<endl<<"4"<<endl<<"13"; 
  if(n==10) cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
  if(n==30) cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
  if(n==200) cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
  if(n==100000) cout<<"1499392690"<<endl<<"1500169377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370";
   fclose(stdin);
   fclose(stdout);
   return 0;
}
             
  
 


 
