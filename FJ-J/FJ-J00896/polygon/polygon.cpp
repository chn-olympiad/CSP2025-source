#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans;
bool flag=true,f[5005];
void dfs(int x)
{
	if(x>n)
	{
		int sum=0,maxn=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1) 
			{
				cnt++,sum+=a[i],maxn=max(maxn,a[i]);
			}
		}
		if(cnt>=3&&sum>2*maxn) ans++,ans%=mod;
		return;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>1) flag=false;
	}
	if(flag)
	{
		for(int i=3;i<=n;i++)
		{
			int sum1=1,sum2=1;
			for(int j=n;j>=n-i+1;j--) sum1*=j,sum1%=mod;
			for(int j=1;j<=i;j++) sum2*=j,sum2%=mod;
			ans+=(sum1/sum2)%mod;
		}
		cout<<ans;
	}
	else
	{
		dfs(1);
		cout<<ans;
 	}
	return 0;
} 
