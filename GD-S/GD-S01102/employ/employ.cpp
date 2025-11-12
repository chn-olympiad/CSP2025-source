#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,P=998244353,M=1<<19;
ll n,m,c[N];
ll a[N];
ll f[2][M][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll tp=1;
	for(ll i=1;i<=n;i++)
	scanf("%1lld",&a[i]),tp&=a[i];
	for(ll i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	ll i=0,maxn=(1<<n)-1;
	f[0][0][0]=1;
	for(ll I=1;I<=n;I++){
		i^=1;
		for(ll s=0;s<=maxn;s++){
			ll tot=0;
			for(ll j=1,w=1;j<=n;j++,w<<=1){
				if(s&w)
				tot++;
			}
			if(tot!=I)
			continue;
			//printf("%lld %lld\n",I,s);
			for(ll j=1,w=1;j<=n;j++,w<<=1){
				if(s&w){
					ll t=s^w;
					for(ll ls=0;ls<=I-1;ls++){
						f[i][s][ls+((a[I]==0)|(ls>=c[j]))]+=f[i^1][t][ls];
						f[i][s][ls+((a[I]==0)|(ls>=c[j]))]%=P;
					}
				}
			}
		}
	}
	ll ans=0;
	for(ll i=m;i<=n;i++)
	ans=(ans+f[n&1][maxn][n-i])%P;
	printf("%lld",ans);
	return 0;
}
