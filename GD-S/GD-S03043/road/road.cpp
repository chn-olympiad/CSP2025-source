//彻底疯狂 卡常失败 
#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
#define int long long
struct st{
	int v,w;
	bool operator<(const st &a)const{
		return a.w<w;
	}
};
struct edg{
	int u,v,w;
};
vector<st>g[maxn];
vector<edg>e;
int n,m,k,vis[maxn],cnt,a;
priority_queue<st>q;
int prim(){
	q.push({1,0});
	int ans=0;
	while(q.size()&&cnt<n){
		int u=q.top().v;
		int _=q.top().w;
		q.pop();
		if(vis[u]) continue;
		ans+=_;
		//cout<<"ans += "<<_<<" , "<<"ans = "<<ans<<endl;;	
		cnt++;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(!vis[v]){
				q.push({v,w});
			}
		}
	}
	return ans;
}
bool cmp(edg a,edg b){
	return a.w<b.w;
}
int fa[maxn];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x]; 
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=yy;
}
int kruskal(){
	int ans=0,cnt=0;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		ans+=e[i].w;
		merge(u,v);
		//cout<<"ans+="<<e[i].w<<endl;
	}
	return ans;
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		//cin>>u>>v>>w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>v;
	int x,y;
	for(int i=1;i<=k;i++){
		scanf("%lld",&x); 
		v.clear();
		v.push_back(0);
		for(int j=1;j<=n;j++){
			scanf("%lld",&y);
			v.push_back(y);
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==j) continue;
				int len=v[j]+v[k]+x;
				for(int l=0;l<n;l++){
					if(g[j][l].v==k) g[j][l].w=min(g[j][l].w,len);	
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			e.push_back({i,g[i][j].v,g[i][j].w});
		}
	}
	printf("%lld",prim());
	return 0;
} 
/*
3 3 1
1 3 6
2 3 7
2 1 5
0 7 4 6

4 5 0
1 2 3
2 3 4
3 4 9
4 1 7
1 3 5

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
Bro写了两个算法，都不对 
*/

