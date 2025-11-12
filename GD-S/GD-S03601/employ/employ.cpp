bool Mst;
#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=__uint128_t;
using pii=pair<int,int>;
#define fi first
#define se second
constexpr int N=505,mod=998244353;
inline ll add(ll x,ll y){return (x+=y)>=mod&&(x-=mod),x;}
inline ll Add(ll &x,ll y){return x=add(x,y);}
inline ll sub(ll x,ll y){return (x-=y)<0&&(x+=mod),x;}
inline ll Sub(ll &x,ll y){return x=sub(x,y);}
inline ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)res=res*a%mod;
	return res;
}
int n,m,s[N],c[N],p[N];
ll f[1<<20][20];
bool Med;
int main(){
	cerr<<abs(&Mst-&Med)/1048576.0<<endl;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char o;cin>>o;
		s[i]=o^48;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int d=__builtin_popcount(i)+1;
			for(int j=0;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(!(i>>(k-1)&1))
						Add(f[i|1<<(k-1)][j+(!s[d]||j>=c[k])],f[i][j]);
		}
		ll ans=0;
		for(int i=0;i<=n-m;i++)
			Add(ans,f[(1<<n)-1][i]);
		cout<<ans<<'\n';
	}
	else if(*min_element(s+1,s+n+1)){
		ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans<<'\n';
	}
	return 0;
}

