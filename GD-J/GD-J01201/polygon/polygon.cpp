#include<iostream>
using namespace std;
int a[5005],dp[5005];
int n,ans=0;
const int N=998244353;

void dfs(int now,bool choose,int maxn,int c)
{
	if(now>n)return;
	if(choose)
	{
		maxn=max(maxn,a[now]);
		c+=a[now];
		if(c>maxn*2)ans++;
	}
	dfs(now+1,0,maxn,c);
	dfs(now+1,1,maxn,c);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	

	dfs(1,0,0,0);
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
	
	
	return 0;
}
