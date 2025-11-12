#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans[5001],print;
bool v[5001];
void dfs(int s,int t)
{
	if(s==n+1)
	{
		int c=0,maxn=0;
		for(int i=1;i<=n;i++)
		{
			c+=v[i]?a[i]:0;
			maxn=max(maxn,v[i]?a[i]:0);
		}
		if(c>maxn*2) print=(print+1)%998244353;
		return;
	}
	v[s]=0;
	dfs(s+1,t+1);
	v[s]=1;
	dfs(s+1,t+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<print;
	return 0;
}
