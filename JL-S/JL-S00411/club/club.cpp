#include<bits/stdc++.h>
using namespace std;
int a[10001][10001],n,x,t;
int main()
{
	freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);	
	cin>>t;	
cin>>n;
if(n%2==0)
{
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
	cin>>a[i][j];
}
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
x=max(a[1][j],a[1][j+n]);
}

for(int i=0;i<=n;i++)
for(int j=0;j<=n;j++)
{
	
cout<<x;
}
}	
	return 0;
}
