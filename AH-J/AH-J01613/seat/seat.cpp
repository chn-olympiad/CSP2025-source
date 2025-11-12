#include<bits/stdc++.h>
using namespace std;
int a[110];
int s;
int y,v;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int x=1;
int z=1;
int c=n*m;
for(int i=1;i<=c;i++)
{
cin>>a[i];
}
for(int i=2;i<=c;i++)
{
if(a[1]<a[i])
{
x++;
}
}
for(int i=1;i<=c;i+=n)
{
if(x>=i&&x<i+n)
{
if(z%2==0)
{
y=x-(i-1);
v=n-y+1;
break;
}
else if(z%2==1)
{
v=x-(i-1);
break;
}
}
z++;
}
cout<<z<<" "<<v;
return 0;
}
