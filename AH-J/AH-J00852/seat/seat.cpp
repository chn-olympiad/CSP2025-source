#include<bits/stdc++.h>
using namespace std;
long long i,j,k,num,n,m,c,r,a[100001],l;//c列，r行
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;//n为行数，m为列数
for(i=1;i<=n*m;i++)
cin>>a[i];
k=a[1];
for(j=1;j<=n*m;j++)
for(i=1;i<=n*m;i++)
if(a[i]<a[i+1])
swap(a[i],a[i+1]);
for(l=1;l<=a[n*m];l++)
if(a[l]==k)
{
if(l==1)
{
cout<<"1 1"<<endl;
break;
}
else if(l==n*m)
{
cout<<m<<n;
break;
}
else 
{
	c=(l-1)/n+1;
    if(c%2==1)
    r=(l-1)%n+1;
    if(c%2==0)
    r=n*c+1-l;
    break;
}
break;
}cout<<c<<" "<<r;
/*
for(i=1;i<=n*m;i++)
cout<<a[i];
*/
return 0;
}

