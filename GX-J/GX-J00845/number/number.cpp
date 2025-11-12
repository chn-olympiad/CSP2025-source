#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
long long i,j,n,t=-1,w,a[1000001];
char s[1000000];
cin>>s;
n=strlen(s);
 for(i=0;i<=n;i++)
 {
     if(s[i]>='0'&&s[i]<='9'){t++;a[t]=s[i]-'0';}
 }
 //for(i=0;i<=t;i++){cout<<a[i]<<endl;}cout<<" "<<t;
   for(i=0;i<t;i++)
    {
     for(j=i+1;j<=t;j++)
     {
         if(a[i]<a[j]){w=a[i];a[i]=a[j];a[j]=w;}
     }
  }
  //for(i=0;i<=t;i++){cout<<a[i]<<endl;}
  for(i=0;i<=t;i++)
  {
      cout<<a[i];
  }
 return 0;
}
