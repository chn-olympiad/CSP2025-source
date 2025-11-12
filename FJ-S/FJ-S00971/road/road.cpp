#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

struct e{
	ll u,v,w;
	e(){}
	e(ll u,ll v,ll w):u(u),v(v),w(w){}
	bool operator<(const e b) const{return w<b.w;}
};

ll n,m,k;
ll c[15],a[15][10005];
e gr[1200005]; ll cnt=0;
ll fa[10050];
bool vst[10050];

ll getfa(ll a){return fa[a]==a?a:fa[a]=getfa(fa[a]);}

ll krs(){
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	sort(gr+1,gr+1+cnt);
	memset(vst,0,sizeof(vst));
	ll ans=0,cn=0;
	for(ll i=1;i<=cnt;i++){
		ll u=gr[i].u,v=gr[i].v,w=gr[i].w;
		ll fu=getfa(u),fv=getfa(v);
		if(fu!=fv){
			fa[fu]=fv; ans+=w;
			if(u<=n&&!vst[u]) cn++;
			if(v<=n&&!vst[v]) cn++;
			vst[u]=1; vst[v]=1;
			if(u>n) ans-=c[u-n];
		}
		if(cn>=n) break;
	}
	for(ll i=1;i<=k;i++){
		if(vst[i+n]) ans+=c[i];
	} 
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w; cin>>u>>v>>w;
		gr[++cnt]=e(u,v,w);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			gr[++cnt]=e(i+n,j,a[i][j]+c[i]);
		}
	}
	cout<<krs()<<endl;
	return 0;
}

