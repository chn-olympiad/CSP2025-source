#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans;
int a[5005];
int cnt[5005];
int sum[5005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt[0]=sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		ans+=sum[a[i]+1];
		ans%=mod;
		cnt[5001]=(sum[5000-a[i]+1]+cnt[5001])%mod;
		for(int j=5000;j>=a[i];j--)
		{
			cnt[j]=(cnt[j-a[i]]+cnt[j])%mod;
		}
		for(int j=5001;j>=0;j--)
		{
			sum[j]=(sum[j+1]+cnt[j])%mod;
		}
	}
	cout<<ans;
}
