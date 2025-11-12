#include<iostream>
using namespace std;
long long a[5001];
long long pai(long long,long long);
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long i,j,n,s=0;
cin>>n;
for(i=1;i<=n;i++)
    cin>>a[i];
for(i=1;i<=n;++i)
    for(j=1;j<=n-i;++j)
{
    if(pai(i,j)) ++s;
}
cout<<s;
return 0;
}

long long pai(long long e,long long d)
{
    long long c[50001],f=0,i,p=0,j,l=0;
    for(i=e;i<=d;++i)
    {p++;c[p]=a[i];}
    for(i=1;i<=p;++i)
        for(j=1;j<=p;++j)
        if(c[i]<c[j]) swap(c[i],c[j]);
for(i=1;i<p;++i)
    l+=c[i];
if(l>c[p]) f=1;
return f;
}
