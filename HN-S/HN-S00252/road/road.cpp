#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[114514],cnt;
struct edge{
	int u,v,w;
	bool operator<(const edge&s)const{
		return w<s.w;
	}
}g[114514];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,g[++cnt]={u,v,w};
	sort(g+1,g+m+1);
	int ans=0,tot=0;
	for(int i=1;i<=m;i++){
		if(find(g[i].u)!=find(g[i].v)){
			fa[find(g[i].u)]=find(g[i].v);
			tot++;
			ans+=g[i].w;
			if(tot==n-1)break;
		}
	}
	cout<<ans;
	return 0;
}

