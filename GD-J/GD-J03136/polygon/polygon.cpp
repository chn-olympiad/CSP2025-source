#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=5001;
const int mod=998244353;
int n,ans,a[5010],b[5010],s[5010];

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=maxn;j++) ans=(ans+s[j])%mod;
		for(int j=0;j<=maxn;j++) b[j]=s[j];
		for(int j=0;j<=maxn;j++)
		{
			int tmp=min(maxn,j+a[i]);
			b[tmp]=(b[tmp]+s[j])%mod;
		}
		for(int j=0;j<=maxn;j++) s[j]=b[j];
	}
	cout<<ans<<endl;
	return 0;
}
