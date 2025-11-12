#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010,mod=998244353;
ll n,a[N],f[N][N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=a[i]+1;j<=a[n]+1;j++)
			ans=(ans+f[i-1][j])%mod;
		for(ll j=0;j<=a[n]+1;j++){
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			f[i][min(a[n]+1,j+a[i])]=(f[i][min(a[n]+1,j+a[i])]+f[i-1][j])%mod;}
	}
	cout<<ans<<endl;
	return 0;
} 
