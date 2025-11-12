#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
struct Node {
	ll u;
	ll v;
	ll w;
}edge[1500005];
ll c[15];
ll dis[15][10005];
int father[10015];
ll ans;
bool cmp(Node a,Node b) {
	return a.w<b.w;
}
int find(int x) {
	if(father[x]==x) return x;
	return father[x]=find(father[x]);
}
int vis[15];
ll sum(int now) {
	for(int i=1;i<=k;i++) 
		vis[i]=0;
	int cnt=k;
	ll pt=0;
	while(now) {
		if(now%2==1) {
			pt+=c[cnt];
			vis[cnt]=1;
		}
		now/=2;
		cnt--;
	}
	return pt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>dis[i][j];
			edge[m+(i-1)*n+j].u=n+i,edge[m+(i-1)*n+j].v=j,edge[m+(i-1)*n+j].w=dis[i][j];
		}
	}
	sort(edge+1,edge+m+n*k+1,cmp);
	for(int i=1;i<=n+k;i++) 
		father[i]=i;
	ll numedge=0,anstot=0;
	for(int i=1;i<=m;i++) {
		int fu=find(edge[i].u);
		int fv=find(edge[i].v);
		if(fu==fv) continue;
		numedge++;
		anstot+=edge[i].w;
		father[fu]=fv;
		if(numedge==n+k-1) break;
	}
	cout<<anstot<<endl;
	return 0;
}
