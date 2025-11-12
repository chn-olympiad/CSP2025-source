#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[10010];
struct node{
	int u,v,w;
}e[100010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int newr[15][10010];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
int ist[15],ans=0x7f7f7f7f;
void dfs(int id){
	if(id==k+1){
		for(int i=1;i<=n;i++) f[i]=i;
		int sum=0;
		node ne[100010];
		for(int i=1;i<=m;i++){
			ne[i].u=e[i].u;
			ne[i].v=e[i].v;
			ne[i].w=e[i].w;
		}
		for(int i=1;i<=k;i++){
			if(ist[i]==0) continue;
			sum+=newr[i][0];
			for(int j=1;j<=n;j++){
				if(ne[j].u==i){
					ne[j].w=newr[i][ne[j].v];
				}else if(ne[j].v==i){
					ne[j].w=newr[i][ne[j].u];
				}
			}
		}
		sort(ne+1,ne+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=ne[i].u,y=ne[i].v;
			int fx=find(x),fy=find(y);
			if(fx==fy) continue;
			merge(fx,fy);
			sum+=ne[i].w;
		}
		ans=min(ans,sum);
		return;
	}
	ist[id]=1;
	dfs(id+1);
	ist[id]=0;
	dfs(id+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>newr[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}

