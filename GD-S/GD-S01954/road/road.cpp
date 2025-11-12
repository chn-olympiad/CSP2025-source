#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,n2,m,m2,k,u,v,w,c[25],a[25][1000005],ans;
struct node{
	int v,w;
};
node b[1000015];
vector<node> g[1000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;n2=n;m2=m;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		b[i].w=w,b[i].v=i;
	}
	int C=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		C=min(C,c[i]);
		for(int j=1;j<=n;j++){
			cin>>w;
			g[++n2].push_back({j,w});
			g[j].push_back({n2,w});
			b[++m2].w=w;b[m2].v=m2;
		}
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<n;i++){
		ans+=b[i].w;
		if(b[i].v>m)ans+=c[m2-m];
	}
	cout<<ans;
}

