#include<bits/stdc++.h>
using namespace std;
int a[5010],ans,n;
void dfs(int i,int v,int s)
{
	if((v>(2*a[i-1]))&&(s>=3))
	{
		ans=(ans+1)%998244353;
	}
	if(i>n) return ;
	dfs(i+1,v,s);
	dfs(i+1,v+a[i],s+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
