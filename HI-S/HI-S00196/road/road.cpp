#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
struct node{
	ll x,y,w;
}path[2000005],edge[2000005];
ll c[15];
ll a[15][10005];
ll f[11005];
int cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
ll solve(int tot){
	ll ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=tot;i++){
		int x=edge[i].x,y=edge[i].y,w=edge[i].w;
		int fx=find(f[x]),fy=find(f[y]);
		if(fx!=fy){
			f[fx]=fy;
			ans+=w;
		}
	}
	return ans;
}
ll make(){
	ll ans=1e17;
	for(int i=0;i<(1<<k)-1;i++){
		for(int u=1;u<=m;u++) edge[u]=path[u];
		int tot=m,res=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				res+=c[j+1];
				for(int o=1;o<=n;o++){
					tot++;
					edge[tot]=(node){n+j+1,o,a[j+1][o]};
				}
			}
		}
		sort(edge+1,edge+1+tot,cmp);
		ans=min(ans,res+solve(tot));
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>path[i].x>>path[i].y>>path[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<make();
	return 0;
}

