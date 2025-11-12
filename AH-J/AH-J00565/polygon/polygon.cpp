#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,ans;
void dfs(int step,int sum,int maxn)
{
	if(step>n)
	{
		if(sum>maxn*2)
			ans++;
		return ;
	}
	int x=maxn;
	if(a[step]>maxn)
		maxn=a[step];
	dfs(step+1,sum+a[step],maxn);
	maxn=x;
	dfs(step+1,sum,maxn);
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn2=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn2=max(a[i],maxn2);
	}
	if(n<3)cout<<0;
	else if(n==3)
	{
		if(sum>maxn2*2)
			cout<<1;
		else cout<<0;
	}
	else 
	{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
