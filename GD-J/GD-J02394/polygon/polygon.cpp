#include<bits/stdc++.h>
using namespace std;
int a[5001],b;
int n,s=0,r;
void dfs(int x)
{
	if(b>a[r]) s=(s+1)%998244353;
	for(int i=x;i<r;i++)
	{
		b+=a[i];
		dfs(i+1);
		b-=a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		r=i;
		dfs(1);	
	}
	cout<<s;
	return 0;	
}
