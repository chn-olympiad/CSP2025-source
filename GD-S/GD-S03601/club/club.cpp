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
constexpr int N=5e5+5,mod=998244353;
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
int n,a[N][3],id[N][3],mx[N],smx[N];
int vec[N],len;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	int cnt[3]={},ans=0;
	for(int i=1;i<=n;i++){
		id[i][0]=0,id[i][1]=1,id[i][2]=2;
		sort(id[i],id[i]+3,[&](int x,int y){return a[i][x]>a[i][y];});
		mx[i]=a[i][id[i][0]],smx[i]=a[i][id[i][1]];
		ans+=mx[i],++cnt[id[i][0]];
	}
	int pos=max_element(cnt,cnt+3)-cnt;
	if((cnt[pos]<<1)>n){
		len=0;
		for(int i=1;i<=n;i++)
			if(id[i][0]==pos)
				vec[++len]=mx[i]-smx[i];
		sort(vec+1,vec+len+1);
		int lim=cnt[pos]-(n>>1);
		for(int i=1;i<=lim;i++)
			ans-=vec[i];
	}
	cout<<ans<<'\n';
}
bool Med;
int main(){
	cerr<<abs(&Mst-&Med)/1048576.0<<endl;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _Test;cin>>_Test;
	while(_Test--)Solve();
	return 0;
}
