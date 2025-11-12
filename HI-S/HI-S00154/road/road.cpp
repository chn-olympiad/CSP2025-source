#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+10, M=1e6+10;

#define ll unsigned long long

int n,m,k,c[15],a[15][N], fa[N];

struct edge {
	int u,v,w;
}es[M*2], d[N*15], od[N*15], cd[N*15];

bool cmp(edge a, edge b) {
	return a.w<b.w;
}

int find(int x) {
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}

bool sas(int a, int b){
	return find(a)==find(b);
}

void unin(int a, int b) {
	if(!sas(a,b)) {
		int k1=find(a),k2=find(b);
		fa[k1]=k2;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		fa[i]=i;
	}
	for(int i=1;i<=m;i++) {
		int u,v,w; cin>>u>>v>>w;
		es[i].u=v, es[i].v=u, es[i].w=w;
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	
	int g=0;
	sort(es+1,es+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++) {
		if(!sas(es[i].u, es[i].v)) {
			ans+=es[i].w;
			unin(es[i].u, es[i].v);
			
			++g; d[g]=es[i];
		}
	}
	int tot=n-1;
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n+k;j++)fa[j]=j;
		int otot=tot;
		for(int j=1;j<=tot;j++) {
			od[j]=d[j];
		}
		for(int j=1;j<=n;j++) {
			++tot;
			
			d[tot].u=n+i;
			d[tot].v=j;
			d[tot].w=a[i][j];
		}
		sort(d+1,d+tot+1,cmp);
		ll q=0;
		int r=0,t=0;
		for(int j=1;j<=tot;j++) {
			if(!sas(d[j].u, d[j].v)) {
				++t; cd[t]=d[j];
				
				unin(d[j].u, d[j].v); 
				q+=d[j].w;
				
				if(d[j].u==n+i||d[j].v==n+i) {
					r++;
				}
			}
		}
		if(r==1) {
			tot=otot;
			for(int j=1;j<=otot;j++) {
				d[j]=od[j];
			}
		}else {
			ans=min(ans, q+c[i]);
			for(int j=1;j<=t;j++) {
				d[j]=cd[j];
			}
			tot=t;
		}
	}
	cout<<ans;
	return 0;
}
