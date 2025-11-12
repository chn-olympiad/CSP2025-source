//CSP 2025 RP++    
#include <bits/stdc++.h>
#define N 1000010
#define M 1010 
#define int long long
using namespace std;
int n,m,k,fa[N],c[M][M];
struct node{
	int u,v,w;
}e[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		int x; cin>>x;
		if(x) flag=0;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]) flag=0;
		} 
	}
	if(!k){
		sort(e+1,e+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=m;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv){
				fa[fu]=fv;
				ans+=e[i].w;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
	}
	if(flag){
		for(int i=n+1;i<=n+k;i++) fa[i]=i;
		int s=m;
		for(int i=n+1;i<=n+k;i++){
			for(int j=1;j<=m;j++){
				e[++s].u=i; e[s].v=j;
			}
		}
		int ans=0,cnt=0;
		for(int i=1;i<=s;i++){
			int fu=find(e[i].u);
			int fv=find(e[i].v);
			if(fu!=fv){
				ans+=e[i].w;
				fa[fv]=fu;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//20
