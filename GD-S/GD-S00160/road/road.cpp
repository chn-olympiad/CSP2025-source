#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,fa[10005],sz[10005];
ll a[15][10005],c[15];
struct node{
	int u,v;
	ll w;
}ed[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i,sz[i]=1;
	}
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[x]=y;
	sz[y]+=sz[x]; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	init();
	if(k==0){
		sort(ed+1,ed+1+m,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++){
			int x=find(ed[i].u),y=find(ed[i].v);
			if(x==y)continue;
			merge(x,y);
			ans+=ed[i].w;
			if(sz[find(y)]==n){
				break;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
