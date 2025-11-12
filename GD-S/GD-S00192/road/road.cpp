#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
const int maxn=1e6+100;
int t,n,m,k,cnt;
struct node{
	int x,y,w;
}g[maxn],g2[maxn],g3[11][10010],g4[maxn];
bool cmp (node a,node b){
	return a.w<b.w;
}
int fa[maxn];
int find(int x){
	if (fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
int c[11],val[11][10010];
set<int> p;
int nxt[11];
int calc(int x){
	int res=0;
	for (int i=1;i<=n+k;i++)fa[i]=i;	
	p.clear();
	int ct=0;
	for (int i=1;i<=k;i++){
		if ((x>>(i-1))&1){
			p.insert(i);ct++;
			res+=c[i];
		}
		nxt[i]=1;
	}
	int tot=0;
	for (int i=1;i<=ct*n;i++){
		int mi=1e18,id=0;
		for (auto j:p){
			if (g3[j][nxt[j]].w<mi){
				mi=g3[j][nxt[j]].w;
				id=j;
			}
		}
//		cout<<ct<<' '<<n<<' '<<i<<'\n';
		g4[++tot]=g3[id][nxt[id]];
		nxt[id]++;
		if (nxt[id]>n)p.erase(p.find(id));
	}
//	for (int i=1;i<=tot;i++){
//		cout<<g4[i].x<<' '<<g4[i].y<<' '<<g4[i].w<<'\n';
//	}
	int j=1;
	for (int i=1;i<=cnt;i++){
		while (j<=tot&&g4[j].w<g2[i].w){
			int x=g4[j].x,y=g4[j].y;
			x=find(x);y=find(y);
			if (x==y){j++;continue;}
			merge(x,y);
			res+=g4[j].w;
			j++;
		}
		int x=g2[i].x,y=g2[i].y;
		x=find(x);y=find(y);
		if (x==y)continue;
		merge(x,y);
		res+=g2[i].w;
	}
	return res;
}
void work(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>g[i].x>>g[i].y>>g[i].w;
	}
	sort(g+1,g+m+1,cmp);
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++)cin>>g3[i][j].w,g3[i][j].x=i+n,g3[i][j].y=j;
		sort(g3[i]+1,g3[i]+n+1,cmp);
	}
	int ans=0;
	for (int i=1;i<=m;i++){
		int x=g[i].x,y=g[i].y;
		x=find(x);y=find(y);
		if (x==y)continue;
		g2[++cnt]=g[i];
		merge(x,y);
		ans+=g[i].w;
	}
//	for (int i=1;i<=cnt;i++)cout<<g2[i].x<<' '<<g2[i].y<<' '<<g2[i].w<<'\n';
//	cout<<calc(1)<<'\n';
	for (int i=1;i<(1<<k);i++){
		ans=min(ans,calc(i));
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	t=1;
	while (t--){work();}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
