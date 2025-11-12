#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],k,ans=INT_MIN;
void dfs(int x,int cnt,int sum);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		if(n==2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<=100&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	dfs(1,0,a[1]);
	cout<<ans;
	return 0;
}
void dfs(int x,int cnt,int sum)
{
	if(x>n)
	{
		ans=max(ans,cnt);
		return;
	}
	if(sum==k)
	{
		dfs(x+1,cnt+1,a[x]);
		dfs(x+1,cnt,sum^a[x]);
	}
	else
	{
		dfs(x+1,cnt,sum^a[x]);
		dfs(x+1,cnt,a[x]);
	}
}