#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[200005],n,ans;
void dfs(int k,int cnt,int sum,int mx)
{
	if(k==n)
	{
		if(cnt>=3&&sum>2*mx)ans++;
		ans%=mod;
		return;
	}
	dfs(k+1,cnt,sum,mx);
	dfs(k+1,cnt+1,sum+a[k+1],max(mx,a[k+1]));
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=25)
	{
		dfs(0,0,0,0);
		cout<<ans;
	}
	else
	{
		int sum=n*(n-1);
		int ans=0,c=2;
		sum/=2;
		for(int i=3;i<=n;i++)
		{
			int s=n-i+1,c=i;
			sum*=s;
			sum/=c;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}