#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100050],cnt;
struct node{
	int u,v,w;
}G[2000050];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int u,int v){
    u=find(u),v=find(v);
	f[u]=v;
	return ;
}
bool cmp(node i,node j){
	return i.w<j.w;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		if(tmp==0){
			for(int j=1;j<=n;j++){
				int t;
				cin>>t;
				G[++cnt]={i+m,j,t};
			}
		}
	}
	sort(G+1,G+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(find(G[i].u)!=find(G[i].v)){
			merge(G[i].u,G[i].v);
			ans+=G[i].w;
		}
	}
	cout<<ans;
	return 0;
}