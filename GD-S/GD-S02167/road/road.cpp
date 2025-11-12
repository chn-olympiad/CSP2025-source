#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5;
typedef pair<int,int> PII;
#define x first
#define y second
struct node {
	int ne,v,w;
} e[2*M];
int n,m,k,c[15],b[15],aa[15][N];
int h[N],cnt;
PII a[15][N];
bool used[15];
void add(int u,int v,int w) {
	e[++cnt].ne=h[u];
	e[cnt].v=v,e[cnt].w=w;
	h[u]=cnt;
}
priority_queue<PII> q[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w; i<=m; i++) {
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		b[i]=1;
		for(int j=1; j<=n; j++) {
			cin>>a[i][j].x;
			aa[i][j]=a[i][j].x;
			a[i][j].y=j;
		}
		sort(a[i]+1,a[i]+1+n);
	}
	set<int> ok;
	ok.insert(1);
	for(int i=h[1]; i; i=e[i].ne) {
		q[1].push(make_pair(-e[i].w,e[i].v));
	}
	ll ans=0;
	while(ok.size()<n) {
		int v=0,w=-2e9;
		for(int u:ok) {
			int vv=0,ww=2e9;
			while(!q[u].empty()) {
				vv=q[u].top().y,ww=-q[u].top().x;
				q[u].pop();
				if(!ok.count(vv))break;
			}
			if(vv!=0&&ww<w)v=vv,w=ww;
			for(int i=1; i<=k; i++) {
				int ww=aa[i][u];
				if(!used[i])ww+=c[i],used[i]=1;
				while(b[i]<=n
				&&(ok.count(a[i][b[i]].y)
				||a[i][b[i]].y==u))
					b[i]++;
				if(b[i]>n)continue;
				ww+=a[i][b[i]].x;
				if(ww<w)w=ww,v=a[i][b[i]].y;
			}
		}
		ok.insert(v);
		ans+=w;
		for(int i=h[v]; i; i=e[i].ne) {
			q[v].push(make_pair(-e[i].w,e[i].v));
		}
	}
	cout<<ans<<'\n';
	return 0;
}

