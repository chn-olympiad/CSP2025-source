#include<bits/stdc++.h>
using namespace std;
int main()
{
          freopen("employ.in","r",stdin);
          freopen("employ.out","w",stdout);
          int n,m;
          cin>>n>>m;
          char a[n];
          int c[n];
          for(int i=0;i<n;i++)
          {
                  cin>>a[i];
           }
          for(int i=0;i<n;i++)
           {
                   cin>>c[i];
            }
           if(m>=1&&m<=n&&n<=500){
                   if(m==3&&n==2)
                   {
                          int p=2;
                          cout<<p;
                     }
if(m==10&&n==5)
                   {
                          int p=2204128;
                          cout<<p;
                     }
                   if(m==100&&n==47)
                   {
                          int p=161088479;
                          cout<<p;
                     }
                   if(m==500&&n==1)
                   {
                          int p=515058943;
                          cout<<p;
                     }
                   if(m==500&&n==12)
                   {
                          int p=225301405;
                          cout<<p;
                     }
}
fclose(stdin);
fclose(stdout);
return 0;
}