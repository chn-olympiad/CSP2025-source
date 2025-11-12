#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[10015],fa[10015],ans=5e18;
bool f[15];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct node{int u,v,w,id;};
bool cmp(node a,node b){return a.w<b.w;}
vector<node>vx;
int sc(){
	for(int i=1;i<=n;i++)fa[i]=i;
	int sum=0;
	for(int i=0;i<vx.size();i++){
		int u=vx[i].u,v=vx[i].v,w=vx[i].w,id=vx[i].id;
		if(!f[id]||find(u)==find(v))continue;
		sum+=w;
		fa[find(u)]=find(v);
	}
	return sum;
}
void dfs(int x,int sum){
	if(x>k){
		int t=sum+sc();
		ans=min(ans,t);
		return;
	}
	f[x]=0;
	dfs(x+1,sum);
	f[x]=1;
	dfs(x+1,sum+c[x+n]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vx.push_back({u,v,w,0});
	}
	f[0]=1;
	for(int i=1;i<=k;i++){
		bool fx=1;
		cin>>c[n+i];
		if(c[n+i])fx=0;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			if(w)fx=0;
			vx.push_back({j,n+i,w,i});
		}
		if(fx){
			cout<<0;
			return 0;
		}
	}
	sort(vx.begin(),vx.end(),cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}
