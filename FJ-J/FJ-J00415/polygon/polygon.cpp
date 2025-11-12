#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=998244353,lim=5000;
int a[5010];
long long f[5010],ans,cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=lim;j++)ans=(ans+f[j])%mod;
		ans=(ans+cnt)%mod;
		cnt=(cnt+cnt)%mod;
		for(int j=lim-a[i]+1;j<=lim;j++)cnt=(cnt+f[j])%mod;
		for(int j=lim;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<ans<<'\n';
	return 0;
}
