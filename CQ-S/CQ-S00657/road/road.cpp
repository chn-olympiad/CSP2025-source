#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls k<<1
#define rs k<<1|1
#define maxn 2000005
struct node{
	int u,v,w;
}e[maxn],q[maxn];
vector<node> G;
int n,m,k,cnt,c[maxn],fa[maxn],vis[maxn],ans,d[maxn];
bool cmp(node a,node b){
	return a.w<b.w;
} 
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	e[++cnt]={u,v,w};
//    	G[u].push_back(v);
//    	G[v].push_back(u);
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			e[++cnt]={j,n+i,x+c[i]};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		int mx=max(u,v);
		if(mx>n)d[mx]++;
		ans+=w;
		fa[fu]=fv;
		G.push_back({u,v,w});
	}
	for(auto i:G){
		int u=i.u,v=i.v,w=i.w;
		if(u<v)swap(u,v);
		if(u>n){
			if(d[u]<2){
				ans-=w;
				continue;
			}
			if(vis[u-n]==0){
			ans-=(d[u]-1)*c[u-n];
			vis[u-n]=1;
			}
		}
		//cout<<u<<v<<w<<endl;
	}
	
	cout<<ans;
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
2 9 3 5
*/
