#include<bits/stdc++.h>
# define Maxn 5005
# define ll long long
# define mod 998244353
using namespace std;
int n,a[Maxn];
ll g[Maxn],d[Maxn],f[Maxn];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	g[0]=d[0]=1;
	for(int i=1;i<=n;i++) {
		f[i]=(f[i-1]+d[a[i]+1])%mod;
		for(int j=5000;j>=0;j--) {
			int v=min(5000,j+a[i]);
			g[v]=(g[v]+g[j])%mod;
		}
		for(int j=5000;j>=0;j--)
		d[j]=(d[j+1]+g[j])%mod;
	}printf("%lld\n",f[n]);
	return 0;
}
