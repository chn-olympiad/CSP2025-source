#include<iostream>
using namespace std;
int a,b;
int n,m,as,qw;
int main()
{
cin>>b>>a;
int x[a*b+10];
for(int i=1;i<=a*b+10;i++)
{
    cin>>x[i];
    n=x[1];
}
for(int i=1;i<=a*b+10;i++)
{
if(x[i]<x[i+1])
{
   m=x[i];
   x[i]=x[i+1];
   x[i+1]=m;
}
}
for(int i=1;i<=a*b+10;i++)
{
if(x[i]==n)
{
 m=i;
}
}
as=m/a+1;
if(as%2==0)
{
    qw=b-m%a+1;
}
else
{
qw=m%a;
}
cout<<as<<" "<<qw;
return 0;
}
