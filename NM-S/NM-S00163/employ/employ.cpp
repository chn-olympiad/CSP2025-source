#include<iostream>
#include<cstdio>
using namespace std;
long long a[100000000];
struct node
{
    int x,y;

};
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
   long long n,m,p;
   cin>>n>>m>>p;
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {


          if(!n==true)
          {
              return true;
          }
          else{
               cnt++;
          }
       }
   }
      if(n+1-n==false)
      {
          return false;
      }
    cout <<cnt;
   return 0;
}
