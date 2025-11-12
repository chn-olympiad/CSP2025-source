//GZ-S00058  遵义市第四中学 刘林志远 
#include <cstdio>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

typedef long long ll;

ll fr() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

const int maxn=1e4+100;
const int maxm=1e6+100;

struct edge{
	int v,w;
};

std::vector<edge> e[maxn];

void ade(int u,int v,int w) {
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}

int n,m,k;

struct ue{
	int u,v,w;
	bool operator< (const ue &u) const& {
		return w<u.w;
	}
}E[maxm];

int cnt;

int f[maxn],sz[maxn];

void init() {
	for(int i = 1; i <= n; i++) f[i]=i,sz[i]=1;
}

int getf(int x) {
	return x==f[x]?f[x]:f[x]=getf(f[x]);
}

void merge(int u,int v) {
	u=getf(u),v=getf(v);
	if(u==v) return;
	if(sz[u]<sz[v]) std::swap(u,v);
	f[v]=u;
	sz[u]+=sz[v];
}

ll ans=0;

int a[11][maxn];
int c[11];

std::vector<int> ktc;
int ck;
int ce[maxn];

ll prim() {
	ll dist[maxn];
	int fa[maxn];
	bool lf[maxn],vis[maxn];
	int r=n+ck;
	for(int i = 0; i <= r; i++) {
		dist[i]=LLONG_MAX;
		vis[i]=0;
		lf[i]=1;
		fa[i]=0;
	}
	dist[1]=0;vis[1]=1;
	for(auto x:e[1]) dist[x.v]=x.w;
	for(int i = 2; i <= r; i++) {
		int aim=0;
		for(int j = 1; j <= r; j++) {
			if(!vis[ktc[j]]&&dist[ktc[j]]<dist[ktc[aim]]) aim=j;
		}
		vis[ktc[aim]]=1;
		for(auto x:e[ktc[aim]]) {
			int v=ktc[x.v];
			if(!vis[v]) {
				if(dist[v]>x.w) {
					fa[v]=ktc[aim];
					dist[v]=x.w;
				}
			}
		}
	}
	ll res=0;
	for(int i = 1; i <= r; i++) res+=dist[ktc[i]],lf[fa[ktc[i]]]=0;
	for(int i = n+1; i <= r; i++) res+=c[ktc[i]-n];
	for(int i = n+1; i <= r; i++) {
		if(lf[ktc[i]]) res-=dist[ktc[i]]+c[ktc[i]-n];
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=fr(),m=fr(),k=fr();
	if(!k) {
		//sub1-4
		init();
		for(int i = 1; i <= m; i++) {
			int u=fr(),v=fr(),w=fr();
			E[++cnt]={u,v,w};
		}
		std::sort(E+1,E+1+m);
		for(int i = 1; i <= m; i++) {
			int u=E[i].u,v=E[i].v,w=E[i].w;
			if(getf(u)==getf(v)) continue;
			ans+=w;
			merge(u,v);
		}
		printf("%lld\n",ans);
	}
	else {
		//sub5-16
		ans=LLONG_MAX;
		for(int i = 1; i <= m; i++) {
			int u=fr(),v=fr(),w=fr();
			ade(u,v,w);
		}
		bool zero=1;
		for(int i = 0; i <= n; i++) ktc.push_back(i); 
		for(int i = 1; i <= k; i++) {
			c[i]=fr();
			if(c[i]) zero=0;
			for(int j = 1; j <= n; j++) {
				a[i][j]=fr();
				e[n+i].push_back({j,a[i][j]});
			}
		}
		if(zero) {
			//A
			ck=k;
			printf("%lld\n",prim());
			return 0;
		}
		for(int st = 0; st < (1<<k); st++) {
			for(int i = 1; i <= n; i++) {
				while(ce[i]--) e[i].pop_back();
				ce[i]++;
			}
			while(ck--) ktc.pop_back();
			ck++;
			for(int i = 0; i < k; i++) {
				if((st>>i)&1) {
					ck++;
					for(int j = 1; j <= n; j++) e[j].push_back({n+i+1,a[i+1][j]});
					ktc.push_back(n+i+1);
				}
			}
			ans=std::min(ans,prim());
		}
		printf("%lld\n",ans);
	}
	return 0;
}

