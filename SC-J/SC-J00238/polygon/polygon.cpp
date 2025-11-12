#include <bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],f[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);int ans=1,ma=a[n];f[0]=1;
	for(int i=1;i<=n;i++)ans=1ll*ans*2%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=a[i];j++)ans=(ans-f[j])%mod;
		for(int j=ma;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<(ans-1+mod)%mod;
	return 0;
}