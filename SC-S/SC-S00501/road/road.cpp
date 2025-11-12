#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,M,k,mp[1005][1005],m[1005][1005],c[15],a[15][1005],cnt,fa[1005],mainans;
struct node {
	int u,v,w;
} edge[10000005];
bool cmp(node a,node b) {
	return a.w<b.w;
}
void minit() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			m[i][j]=mp[i][j];
		}
	}
}
void edgeinit() {
	cnt=0;
	for(int i=1; i<=n; i++) {
		fa[i]=i;
		for(int j=1; j<i; j++) {
			if(m[i][j]!=1e18) {
				edge[++cnt]= {i,j,m[i][j]};
			}
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
}
int findfa(int x) {
	return (fa[x]==x?x:fa[x]=findfa(fa[x]));
}
void mergefa(int a,int b) {
	fa[findfa(a)]=findfa(b);
}
int checkfa(int a,int b) {
	return (findfa(a)==findfa(b));
}
int mktr() {
	int ans=0,cntx=0;
	for(int i=1; i<=cnt; i++) {
		if(checkfa(edge[i].u,edge[i].v)) {
			continue;
		}
		ans+=edge[i].w;
		mergefa(edge[i].u,edge[i].v);
		cntx++;
		if(cntx>(n+1)) {
			break;
		}
	}
	return ans;
}
int tlst[15];
void getans(int op) {
	int ans=0;
	minit();
	for(int i=1; i<=k; i++) {
		if(op||tlst[i]) {
			ans+=c[i];
			for(int u=1; u<=n; u++) {
				for(int v=1; v<u; v++) {
					m[u][v]=m[v][u]=min(m[u][v],a[i][u]+a[i][v]);
				}
			}
		}
	}
	edgeinit();
	mainans=min(mainans,ans+mktr());
}
void mktlst(int id) {
	if(id>n) {
		getans(0);
		return;
	}
	mktlst(id+1);
	tlst[id]=1;
	mktlst(id+1);
	tlst[id]=0;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>M>>k;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			mp[i][j]=1e18;
		}
	}
	for(int i=1; i<=M; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	int cflag=1;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]) {
			cflag=0;
		}
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	mainans=1e18;
	if(cflag) {
		getans(1);
	} else {
		mktlst(1);
	}
	cout<<mainans;
	return 0;
}
