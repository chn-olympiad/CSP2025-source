#include<iostream>
using namespace std;
long long a[101],c[101];
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long i,j,n,h,l,z,p,d,e;
cin>>h>>l;
n=h*l;
//cout<<h<<l<<n;
for(i=1;i<=n;++i)
cin>>a[i];
z=a[1];
for(i=1;i<=n;++i)
c[a[i]]++;
p=0;
for(i=1;i<=z;i++)
if(c[i]==1)  ++p;
//cout<<p;
if(p%h==0) d=p/h;
else d=p/h+1;
if(d%2==0) e=p%h*-2+1+p%h+h;
cout<<d<<"  "<<e;
return 0;
}
