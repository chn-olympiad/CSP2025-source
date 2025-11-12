#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,a[10001],num,l,b,c;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(i=1;i<=n;i++)
cin>>a[i];
sort(a+1,a+1+n);
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
for(k=j+1;k<=n;k++)
if(i+j+k>2*k)
num++;
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
for(k=j+1;k<=n;k++)
for(b=k+1;b<=n;b++)
if(i+j+k+b>2*b)
num++;
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
for(k=j+1;k<=n;k++)
for(b=k+1;b<=n;b++)
for(c=b+1;c<=n;c++)
if(i+j+k+b+c>2*c)
num++;
cout<<num<<endl;
return 0;
}
