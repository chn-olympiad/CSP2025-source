#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e4+7, N2=1e3+7, M=1e6+7;
int n, m, k;
struct edge{
	int u, v;
	ll w;
	edge(){}
	edge(int u, int v, ll w):u(u), v(v), w(w){}
}e[M];int tot=0;
ll len[N2][N2];
ll c[17], cost[17][N];
int fst[17];
int fa[N], cnt;
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
bool join(int x, int y){
	int fx=find(x), fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		cnt--;
		return 1;
	}else return 0;
}
bool cmp(edge x, edge y){
	return x.w<y.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++)
			cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1, e+m+1, cmp);
		cnt=n;
		ll ans=0;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=m && cnt>1;i++)
			if(join(e[i].u, e[i].v))
				ans+=e[i].w;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			len[i][j]=(i==j?0:0x3f3f3f3f3f3f3f3f);
	for(int i=1;i<=m;i++){
		int u, v;ll w;
		cin>>u>>v>>w;
		len[u][v]=len[v][u]=min(len[u][v], w);
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
			if(cost[i][j]==0 && !fst[i])
				fst[i]=j;
		}
		if(!fst[i]) flag=0;
	}
	if(flag){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				len[fst[i]][j]=len[j][fst[i]]=min(len[fst[i]][j], cost[i][j]);
	}else{
		for(int l=1;l<=k;l++){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					len[i][j]=len[j][i]=min(len[i][j], cost[l][i]+cost[l][j]+c[l]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			e[++tot]=edge(i, j, len[i][j]);
	sort(e+1, e+tot+1, cmp);
	cnt=n;
	ll ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=tot && cnt>1;i++)
		if(join(e[i].u, e[i].v))
			ans+=e[i].w;
	cout<<ans<<endl;
	return 0;
}