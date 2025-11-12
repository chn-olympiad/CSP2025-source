#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int n,m,k,cnt,ans;
int fa[maxn];
int ad[maxn];
struct node{
	int u,v,w;
}adj[maxn];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]); 
}
void uni(int a,int b){
	if(find(a)!=find(b)){
		fa[find(a)]=find(b);
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>adj[i].u>>adj[i].v>>adj[i].w;
	}
	for(int i=1;i<=k;++i){
		int val;
		cin>>val;
		for(int j=1;j<=n;++j){
			cin>>ad[j];
		}
		for(int k=1;k<=n;++k){
			for(int l=1;l<=n;++l){
				if(k!=l){
				cnt++;
				adj[m+cnt].u=k;
				adj[m+cnt].v=l;
				adj[m+cnt].w=ad[k]+ad[l];	
				}
			}
		}
	}
	sort(adj+1,adj+1+m+cnt,cmp);
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m+cnt;++i){
		int u1=adj[i].u;
		int v1=adj[i].v;
		int w1=adj[i].w;
		if(find(u1)==find(v1)) continue;
		ans+=w1;
		uni(u1,v1);
	}
	cout<<ans<<endl;
	return 0;
} 