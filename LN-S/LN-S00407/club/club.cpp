#include<bits/stdc++.h>
using namespace std;
int a[100005][100005];
int f[6],p[100005],flag=1;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
int n,sum=0;
cin>>n;
if(n==2)
{
for(int k=1;k<=3;k++)
{
for(int l=1;l<=3;l++)
{
if(l!=k)
{
sum=max(sum,a[1][k]+a[2][l]);
}
}
}
cout<<sum<<endl;
flag=0;
}
if(flag==1)
{
int maxx=n/2;
for(int j=1;j<=n;j++)
{
	cin>>a[j][1];
	p[j]=a[j][1];
}
sort(p+1,p+1+n);
for(int k=1;k<=maxx;k++)
{
f[i]+=p[k];
}
if(flag==1)
{
for(int i=1;i<=t;i++){
cout<<f[i]<<endl;
}
}
}
}
return 0;
}
