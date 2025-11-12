#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
long long fa[50010],siz[50010],du[50010],lin[50010],ans,ansn=1e18;
struct node{
	long long x,y,w;
}g[maxn];
bool cmp(node q,node p){
	return q.w<p.w;
}
inline int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)return;
	if(siz[fx]<siz[fy]){
		siz[fy]+=siz[fx];
		fa[fx]=fy;
	}
	else{
		siz[fx]+=siz[fy];
		fa[fy]=fx;
	}
}
long long n,m,k,c[maxn],ty=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].x>>g[i].y>>g[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])ty=1;
		for(int j=1;j<=n;j++){
			g[m+(i-1)*n+j].x=n+i;
			g[m+(i-1)*n+j].y=j;
			cin>>g[m+(i-1)*n+j].w;
		}
	}
	if(ty==0){
		for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(g+1,g+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		if(find(g[i].x)!=find(g[i].y)){
			merge(g[i].x,g[i].y);
			du[g[i].y]++;
			du[g[i].x]++;
			lin[g[i].x]=g[i].w;
			lin[g[i].y]=g[i].w;
			ans+=g[i].w;
		}
	}
	for(int i=n+1;i<=n+k;i++){
		if(du[i]==1){
			ans-=lin[i];

		}
	}
	cout<<ans;
	return 0;
	}
for(int j=0;j<(1<<k);j++){
		ans=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		sort(g+1,g+m+k*n+1,cmp);
		for(int i=1;i<=m+k*n;i++){
			if(g[i].x<g[i].y)swap(g[i].x,g[i].y);
			if(g[i].x>n&&(((j>>(g[i].x-n-1))&1)==0))continue;
			if(find(g[i].x)!=find(g[i].y)){
				merge(g[i].x,g[i].y);
				ans+=g[i].w;
			}
		}
		for(int i=0;i<k;i++){
			
			if((j>>i)&1){
				ans+=c[1+i];
			}
		}
		ansn=min(ansn,ans);
	}
	cout<<ansn;
	return 0;
}
