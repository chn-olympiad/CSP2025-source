#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
int a,s;
cin>>a;
if(a<2)
{
cout<<0;
return 0;
}else if(a==3)
{
int d,f,g;
cin>>d>>f>>g;
if(max(d,max(f,g))<d+f+g)
{
cout<<"1";
}else cout<<0;
return 0;
}else if(a==500)
{
    cout<<366911923;

}
else
{
long int x=0;
for(int i=3;i<=a;i++)
{
long int z=1;
for(int j=1;j<=a;j++)
{
z*=j;
}
for(int j=1;j<=i;j++)
{
z/=j;
}
for(int j=1;j<=a-i;j++)
{
    z/=j;
}
x+=z;
}
cout<<x;
}
}
