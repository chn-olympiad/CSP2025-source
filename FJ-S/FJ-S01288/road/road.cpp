#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
struct edge{
	int u,v,w;
	static bool cmp(edge x,edge y){
		return x.w<y.w;
	}
};
int n,m,k,ans=INT_MAX,c[15],fa[10100];
vector<edge>e;
bool p=0,used[15];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void check(){
	int cnt=0,ret=0,usen=0;
	for(int i=1;i<=k;i++){
		if(used[i]) ret+=c[i],usen++;
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=0;i<e.size()&&cnt<n+usen-1;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n){
			if(!used[u-n]) continue;
		}
		if(v>n){
			if(!used[v-n]) continue;
		}
		int x=find(u),y=find(v);
		if(x!=y){
			//cout<<u<<" "<<v<<" "<<w<<endl;
			fa[u]=y;
			cnt++;
			ret+=w;
		}
	}
	if(cnt==n+usen-1) ans=min(ans,ret);
	return ;
}
void dfs(int x){
	if(x>k){
		check();
		return ;
	}
	dfs(x+1);
	used[x]=1;
	dfs(x+1);
	used[x]=0;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge x;
		x.u=u,x.v=v,x.w=w;
		e.push_back(x);
		x.u=v,x.v=u;
		e.push_back(x);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) p=1;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			if(w>0) p=1;
			edge x;
			x.u=i+n,x.v=j,x.w=w;
			e.push_back(x);
			x.u=j,x.v=i+n;
			e.push_back(x);
		}
	}
	if(!p){
		cout<<0;
		return 0;
	}
	sort(e.begin(),e.end(),edge::cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
