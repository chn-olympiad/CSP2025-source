#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e4+10;
const int M=5e6+10;
int n,m,k,cnt,ans,cnt2,num;
struct node {
	int u,v,w;
	friend bool operator<(node a,node b) {
		return a.w<b.w;
	}
} g[M],gg[N];
int c[11];
int fa[N];
int juli_k[N][11];
int father(int u) {
	if(u==fa[u]) return u;
	return fa[u]=father(fa[u]);
}
void join(int u,int v) {
	int Fa_u=father(u);
	int Fa_v=father(v);
	if(Fa_u==Fa_v) return;
	fa[Fa_u]=Fa_v;
}
void kruskal(int len) {
	for(int i=1; i<=len; i++) {
		int FA_u=father(g[i].u);
		int FA_v=father(g[i].v);
		if(FA_u==FA_v) continue;
		join(FA_u,FA_v);
		num=num+g[i].w;
		gg[++cnt2]= {g[i].u,g[i].v,g[i].w};
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1; i<=n+k; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[++cnt]= {u,v,w};
	}
	sort(g+1,g+m+1);
	kruskal(m);
	for(int i=1; i<=cnt2; i++) {
		g[i].u=gg[i].u;
		g[i].v=gg[i].v;
		g[i].w=gg[i].w;
	}
	if(k==0) {
		cout<<num;
		return 0;
	}
	ans=num;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>juli_k[j][i];
		}
	}
//	for(int i=1;i<=cnt2;i++) cout<<gg[i].u<<" "<<gg[i].v<<" "<<gg[i].w<<"\n";
	for(int i=1; i<(1<<k); i++) {
		for(int i=1; i<=n+k; i++) fa[i]=i;
		cnt=cnt2;
		num=0;
		for(int j=0; j<k; j++) {
			if(i&(1<<j)) {
				num=num+c[j+1];
				for(int ii=1; ii<=n; ii++) {
					g[++cnt2]= {j+1+n,ii,juli_k[ii][j+1]};
//					cout<<j+1+n<<" "<<ii<<" "<<juli_k[ii][j+1]<<endl;
				}
			}
		}
		sort(g+1,g+cnt2+1);
		kruskal(cnt2);
		ans=min(ans,num);
//		cout<<num<<" "<<ans<<"\n";
		cnt2=cnt;
	}
	cout<<ans<<endl;
}
