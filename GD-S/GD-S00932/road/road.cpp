#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=2e6+5;
const int K=12;
int n,m,k;
struct E{
	int u,v,w;
	bool operator < (const E& x) const{
		return w<x.w;
	}
}e[M];
int c[K],a[K][N];

int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int kruskal(){
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		cnt++;
		ans+=w;
		if(cnt==n-1) return ans;
	}
	return -1;
}

namespace sub1{
	void mian(){
		for(int i=1;i<=k;i++){
			int u=0;
			for(int j=1;j<=n;j++)
				if(a[i][j]==0){
					u=j;
					break;
				}
			for(int v=1;v<=n;v++){
				if(v==u) continue;
				e[++m]={u,v,a[i][v]};
			}
		}
		cout<<kruskal();
	}
}

signed main(){
//	freopen("road3.in","r",stdin);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i]; 
		if(c[i]) flag=false;
		bool fl=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) fl=true;
		}
		if(!fl) flag=false;
	}
	
	if(!k) cout<<kruskal();
	else if(flag) sub1::mian();
	else cout<<kruskal();
	return 0;
}
