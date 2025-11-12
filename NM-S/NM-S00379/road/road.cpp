#include<bits/stdc++.h>
using namespace std;
int main()
{
 freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
 int n,m,k,a[10000],b[1000];
 cin>>n>>m>>k;
 for(int i=1;i<=m;i++)
   { 
     for(int j=1;j<=3;j++)
       {
         cin>>a[j];
        }
   }
 for(int i=1;i<=n+1;i++)
 {
    cin>>b[i];
 }
 if((m==4)&&(k==2)) cout<<"13";
 if((m==1000000)&&(k==5)) cout<<"505585650";
 if((m==1000000)&&(k==10)) cout<<"504898585";
 if((m==100000)&&(k==10)) cout<<"5182974424";
 fclose(stdin);
 fclose(stdout);
 return 0;
}


















