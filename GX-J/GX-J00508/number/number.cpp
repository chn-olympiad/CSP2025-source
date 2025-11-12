#include<iostream>
#include<string>
using namespace std;
int n,m[1010],b;
char a[1010];
string x
int main()
{
    cin>>x;
    a=x;
for(int i=1;i<=x.size();i++)
{
if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
{
    m[i]=a[i];
}
}
for(int j=1;j<=110;j++)
{
for(int i=1;i<=x.size();i++)
{
if(m[i]<m[i+1])
{
b=m[i];
m[i]=m[i+1];
m[i+1]=b;
}
}
}
for(int i=1;i<=x.size();i++)
{if(m[i]==0)
{
break;
}
cout<<m[i];}
return 0;
}
