#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int r[12][10004],r2[1003][1003][10];
struct node{
	int u,v,w;
}e[1000006];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[10004];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void hb(int x,int y){
	fa[x]=find(y);
	return ;
}
struct edge{
	int pre,v,w;
}eg[1000006];
int head[10004],tot;
void make(int u,int v,int w){
	tot++;
	eg[tot].to=v;
	eg[tot].w=w;
	eg[tot].pre=head[u];
	head[u]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;++i){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		for(int i=1;i<=n;++i){
			fa[i]=i;
		}
		sort(e+1,e+m+1,cmp);
		int tot=1;
		for(int i=1;i<=m;++i){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				hb(u,v);
				tot++;
				if(tot==n){
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=m;++i){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		for(int i=1;i<=n;++i){
			fa[i]=i;
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=k;++i){
			int c;
			cin>>c;
			for(int j=1;j<=n;++j){
				int w;
				cin>>w;
				r[i][j]=w;
			}
		}
		int tot=1;
		for(int i=1;i<=m;++i){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				hb(u,v);
				tot++;
				if(tot==n){
					break;
				}
			}
		}
	}
	return 0;
}
