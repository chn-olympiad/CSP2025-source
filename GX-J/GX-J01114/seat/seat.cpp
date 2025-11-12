#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,p;
double a[105],g,b;
int main()
{
freopen("seat.in" ,"r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
cin>>a[i];
}
b=a[1];
for(int i=1;i<=n*m;i++)
{
g=a[n*m];
for(int j=i;j<=m*n;j++)
{
if(g<a[j])
{
g=a[j];
}
}
a[i]=g;
}
for(int i=1;i<=n*m;i++)
{
if(a[i]=b)
{
p=i;
}
}
int s=p/n;
if(p%n==0)
{
    c=s;
}
else
{
    c=s+1;
}
int x=p%n;
if(c%2==0)
{
r=x;
}
else
{
r=n-x-1;
}
cout<<c<<r;
return 0;
}
