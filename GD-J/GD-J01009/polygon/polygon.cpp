#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=5010,N=3,mod=998244353;
ll n,a[M],f[M][N],g[M][N],s,mx;
void add(ll &x,ll y){x=(x+y)%mod;}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(register ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);mx=a[n]+1;
	f[0][0]=1;
	for(register ll i=1;i<=n;i++)
	{
		for(register ll j=a[i]+1;j<=mx;j++)
			s=(s+f[j][2])%mod;
		for(register ll j=0;j<=mx;j++)
			for(register ll k=0;k<=2;k++)
				g[j][k]=f[j][k];
		for(register ll j=0;j<=mx;j++)
			for(register ll k=0;k<=2;k++)
			{
				add(g[min(j+a[i],mx)][min(2ll,k+1)],f[j][k]);
			}
		for(register ll j=0;j<=mx;j++)
			for(register ll k=0;k<=2;k++)
				f[j][k]=g[j][k];
	}
	cout<<s;
	return 0;
}
