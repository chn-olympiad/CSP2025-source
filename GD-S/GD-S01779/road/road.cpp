#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define pb push_back
#define db double
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int MAXN=1e4+20;
const int MAXM=1e6+20;
const int MAXK=11;

int n,m,K,cnt;
ll ans=1ll<<60;
struct Edge {
	int u,v;
	ll w;
	bool operator<(const Edge &rhs) const {
		return w<rhs.w;
	}
}ed[MAXM],ne[MAXM];
ll a[MAXK][MAXN],c[MAXK];
int fa[MAXN];
int get_fa(int x) { return (fa[x]==x)?x:fa[x]=get_fa(fa[x]); }
ll merge(Edge p) {
	int x=get_fa(p.u),y=get_fa(p.v);
	if(x==y) return -1;
	fa[x]=y;
	return p.w;
}
void sol(int nt,ll pre) {
	sort(ne+1,ne+1+cnt);
	for(int i=1;i<=n+K;i++) fa[i]=i;
	int T=n+nt-1,R1=1,R2=1;
	ll res=0;
	while(T>0) {
		Edge p;
		if(R1>m&&R2>cnt) break;
		if(res+pre>=ans) break;
		if(R1>m) p=ne[R2++];
		else if(R2>cnt) p=ed[R1++];
		else {
			if(ed[R1].w<=ne[R2].w) p=ed[R1++];
			else p=ne[R2++];
		}
		ll t=merge(p);
		if(t==-1) continue;
		T--,res+=t;
	}
	ans=min(ans,res+pre);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++) cin>>ed[i].u>>ed[i].v>>ed[i].w;
	for(int i=1;i<=K;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(ed+1,ed+1+m);
	int N=1ll<<K;
	for(int i=0;i<N;i++) {
		//init
		cnt=0;
		ll num=0,res=0;
		for(int j=1;j<=K;j++) {
			if(!((i>>(j-1))&1)) continue;
			num++,res+=c[j];
			for(int t=1;t<=n;t++) ne[++cnt]=(Edge){n+j,t,a[j][t]};
		}
		sol(num+n,res);
	}
	cout<<ans;

	return 0;
}
