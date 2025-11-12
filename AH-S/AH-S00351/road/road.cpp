#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[1000005];
int n,m,k,c[15][10005],f[10005],cnt;
map<int,int>p;
long long ans;
bool cmp(node x,node y){
	return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
		f[u]++;
		f[v]++;
		++cnt;
		a[cnt].u=u,a[cnt].v=v,a[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	sort(a+1,a+cnt+1,cmp);
	
	cout<<ans;
	return 0;
}
