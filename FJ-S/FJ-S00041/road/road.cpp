#include<bits/stdc++.h>
using namespace std;
const int N=10004,M=1e6+4,K=14;
int n,m,k,c[K],a[K][N],pa[N];
struct E{
	int w,u,v;
} h[M];
int find(int i){
	return pa[i]==i?i:pa[i]=find(pa[i]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>h[i].u>>h[i].v>>h[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(h+1,h+m+1,[](E a,E b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)pa[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++){
		int w=h[i].w,u=h[i].u,v=h[i].v;
		if(find(u)==find(v))continue;
		pa[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
}
