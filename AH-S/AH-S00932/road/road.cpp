#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct Edge{
	int u,v,w;
}e[N];
int ans=0,n,m,k,c[20],a[20][N],road[N],sum=0;
int fa[N];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int findfa(int x){
	if(x!=fa[x])return fa[x]=findfa(fa[x]);
	return x;
}
void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=findfa(e[i].u),y=findfa(e[i].v);
		if(x!=y){
			fa[x]=y;
			sum++;
			ans+=e[i].w;
			road[sum]=i;
		}
	}
	if(sum==n-1)return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool ok=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)ok=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)ok=false;
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	kruskal();
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=sum;i>=1;i--){
		int u=e[road[i]].u,v=e[road[i]].v,w=e[road[i]].w;
		ans-=w;
		for(int j=1;j<=k;j++){
			if(w>a[j][u]+a[j][v]+c[j]){
				w=a[j][u]+a[j][v]+c[j];
			}
		}
		ans+=w;
	}
	cout<<ans;
}
