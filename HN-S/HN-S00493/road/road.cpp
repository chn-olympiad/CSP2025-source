#include<bits/stdc++.h>
#define mkp(x,y) make_pair(x,y)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int N=1e4+5,M=1e6+5;

struct node{
	int u,v,w;
	bool operator <(const node &n)const{
		return w<n.w;
	}
}e[M<<1];

int n,m,k;
int c[15],a[15][N],Min[15];
vector<pii> g[N],g1[N],g2[N];

int v[15],cnt;
ll ans,sum,nsum;

int prt[N];

int Find(int x){
	if(x==prt[x])return x;
	return prt[x]=Find(prt[x]);
}

void Kruskal(){
	for(int i=1;i<=n;i++)
		prt[i]=i;
	sort(e+1,e+1+m);
	int tot=0;
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v,ww=e[i].w;
		int X=Find(x),Y=Find(y);
		if(X==Y)continue;
		tot++;
		sum+=ww;
		prt[X]=Y;
		g[x].emplace_back(mkp(y,ww));
		g[y].emplace_back(mkp(x,ww));
	}
}

void dfs(int x,int fa,int p){
	for(int i=0;i<g1[x].size();i++){
		int y=g1[x][i].first,w=g1[x][i].second;
		if(y==fa)continue;
		if(x<=n&&w>a[p][y]){
			g2[y].emplace_back(mkp(n+p,a[p][y]));
			g2[n+p].emplace_back(mkp(y,a[p][y]));
			nsum-=w-a[p][y];
		}else{
			g2[x].emplace_back(mkp(y,w));
			g2[y].emplace_back(mkp(x,w));
		}
		dfs(y,x,p);
	}
	g1[x]=g2[x];
	g2[x].clear();
}

void calc(){
	nsum=sum;
	for(int i=1;i<=n;i++)
		g1[i]=g[i];
	for(int i=1;i<=cnt;i++){
		int x=n+v[i],y=Min[v[i]];
		g1[x].clear();
		g1[x].emplace_back(mkp(y,a[v[i]][y]));
		g1[y].emplace_back(mkp(x,a[v[i]][y]));
		nsum+=c[v[i]]+a[v[i]][y];
		dfs(x,0,v[i]);
	}
//	if(nsum<ans){
//		for(int i=1;i<=cnt;i++)
//			cout<<v[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<i<<":\n";
//			for(auto p:g1[i])
//				cout<<p.first<<' '<<p.second<<endl;
//		}
//		for(int i=1;i<=cnt;i++){
//			cout<<n+v[i]<<":\n";
//			for(auto p:g1[n+v[i]])
//				cout<<p.first<<' '<<p.second<<endl;
//		}
//		cout<<nsum<<endl;
//	}
	ans=min(ans,nsum);
}

void search(int x){
	if(x==k+1){
		calc();
		return;
	}
	search(x+1);
	v[++cnt]=x;
	search(x+1);
	cnt--;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	Kruskal();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		Min[i]=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<a[i][Min[i]])Min[i]=j;
		}
	}
	ans=sum;
	search(1);
	cout<<ans;
	return 0;
}

