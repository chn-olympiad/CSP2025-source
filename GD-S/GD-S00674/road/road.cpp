#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=11e6+10,M=1e4+10,K=15,Z=(1<<5)+4;
int n,m,k,gg;
ll ans,mx,dis[M][Z];
int xw[K][M],cz[K];
bool us[K][M],vis[M][Z];
struct ed{
	int u,v,w,id;
}g[N];
bool cmp(ed x,ed y){
	return x.w<y.w;
}
vector<pair<int,int>>e[N];
int fa[N];
int find(int x){
	return(x==fa[x]?x:fa[x]=find(fa[x]));
}
struct pm{
	int p,xzsta;
	ll dis;
	vector<pair<int,int>>e;
};
bool operator<(pm x,pm y){
	return x.dis>y.dis;
}
priority_queue<pm>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[++gg]={u,v,w,0};
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cz[i];
		for(int j=1;j<=n;j++)
			cin>>xw[i][j];
		for(int j=1;j<=n;j++)for(int kk=j+1;kk<=n;kk++)
			g[++gg]={j,k,0,i};
	}
	sort(g+1,g+gg+1,cmp);
	if(!k){
		ans=0;
		for(int i=1;i<=gg;i++){
			if(find(g[i].u)==find(g[i].v))
				continue;
			int u=find(g[i].u),v=find(g[i].v);
			if(u^v) fa[u]=v,ans+=g[i].w;
		}
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	pm st;
	st.e.clear();
	st.p=1,st.dis=0,st.xzsta=0;
	q.push(st);
	dis[1][0]=0;
	while(q.size()){
		pm f=q.top(),nf;
		cerr<<f.p<<", "<<f.dis<<"\n";
		q.pop();
		nf.e=f.e;
		for(auto v:e[f.p])if(f.dis+v.second<dis[v.first][f.xzsta]){
			if(dis[v.first][f.xzsta]!=dis[0][0])
				mx-=dis[v.first][f.xzsta];
			dis[v.first][f.xzsta]=f.dis+v.second;
			mx+=f.dis+v.second;
			nf.p=v.first,nf.dis=f.dis+v.second,nf.xzsta=f.xzsta;
			q.push(nf);
		}
		for(int i=1;i<=k;i++){
			ll et=0;
			if(((f.xzsta>>(i-1))&1)==0) et=cz[i];
			bool fl=0;
			for(auto v:f.e)if(v.first==i&&v.second==f.p) fl=1;
			if(!fl) et+=xw[i][f.p];
			for(int j=1;j<=n;j++)if(f.p!=j){
				fl=0;
				bool fl2=0;
				for(auto v:f.e)if(v.first==i&&v.second==j) fl2=1;
				if(!fl2) et+=xw[i][j];
				int nsta=f.xzsta|(1<<(i-1)); 
				if(f.dis+et<dis[j][nsta]){
					if(dis[j][nsta]!=dis[0][0])
						mx-=dis[j][nsta];
					dis[j][nsta]=f.dis+et;
					mx+=dis[j][nsta];
					nf.p=j,nf.dis=f.dis+et,nf.e=f.e;
					if(!fl) nf.e.push_back({i,f.p});
					if(!fl2)nf.e.push_back({i,j});
					nf.xzsta=nsta;
					q.push(nf);
				}
				if(!fl2) et-=xw[i][j];
			}
		}
	}
	cout<<mx;
	return 0;
}
