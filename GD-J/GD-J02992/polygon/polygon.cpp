#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010,M=1e4+10,mod=998244353;
ll n,a[N],f[N][M],p[N],ans;  
ll pw(ll x){
	if(!p[x]) p[x]=pw(x>>1)*p[x>>1]*(1<<(x&1))%mod;
	return p[x];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll lim=-1;
	f[0][0]=1,p[1]=2;
	for(ll i=3;i<=n;i++){
		ll num=lim;
		lim=a[i];
		for(ll j=1;j<i-1;j++){
			for(ll k=lim;k>num;k--){
				f[j][k]=f[j-1][k];
				if(k>=a[j]) f[j][k]+=f[j-1][k-a[j]],f[j][k]%=mod;
			}
		}
		ll sum=0;
		for(ll j=lim;j>=0;j--){
			f[i-1][j]=f[i-2][j];
			if(j>=a[i-1]) f[i-1][j]+=f[i-2][j-a[i-1]],f[i-1][j]%=mod;
			sum+=f[i-1][j],sum%=mod;
		}
		ans+=pw(i-1)-sum+mod,ans%=mod;
	}
	cout<<ans;
	return 0;
}
