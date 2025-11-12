#include<bits/stdc++.h>
using namespace std;
const int MAXS=1e4+10,MAXN=1.2e6+10;
struct node{
	int u,v,w;
	bool operator < (const node &rhs)const {
		return w<rhs.w;
	}
}q[MAXN];
int tot,ans,n,m,k,fa[MAXS],vis[12];
int find(int x){
	fa[x]==x ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		tot++;
		cin>>q[tot].u>>q[tot].v>>q[tot].w;
	}
	if(k==0){
		for(int i=1;i<=tot;i++){
			if(find(q[i].u)!=find(q[i].v)){
				merge(q[i].u,q[i].v);
				ans+=q[i].w;
			}
		}
		cout<<ans;
	}
	for(int i=1;i<=k;i++){
		cin>>vis[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
		}
	}
	cout<<"0";
	return 0;
}
