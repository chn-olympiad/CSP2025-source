#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans,cnt,n,m,k,fa[20005],c[15],a[15][10005],vis[10005];
struct node{
	int u,v,w;
}edge[2000005];
const int INF=1e9+1;
bool A=1;
void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i; 
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int minn=INF;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<minn)minn=a[i][j];
		}
		if(minn!=0||c[i]!=0)A=0;
	}
	if(k==0){
		init();
		sort(edge+1,edge+m+1,cmp);
		cnt=0;
		for(int i=1;i<=m;i++){
			int fu=find(edge[i].u),fv=find(edge[i].v);
			if(fu!=fv){
				ans+=edge[i].w;
				fa[fu]=fv;
				cnt++;
				if(cnt==n-1)break;
			}
		} 
		cout<<ans<<'\n';
	}else if(A){
		init();
		for(int i=1;i<=k;i++){
			bool f=0;
			int u=n+i;
			for(int j=1;j<=n;j++){
				if(a[i][j]==0&&f==0){
					f=1;
					int fu=find(u),fv=find(j);
					fa[fu]=fv;
				}else{
					edge[++m]={u,j,a[i][j]};
				}
			}
		}
		sort(edge+1,edge+m+1,cmp);
		cnt=0;
		for(int i=1;i<=m;i++){
			int fu=find(edge[i].u),fv=find(edge[i].v);
			if(fu!=fv){
				ans+=edge[i].w;
				fa[fu]=fv;
				cnt++;
				if(cnt==n-1)break;
			}
		} 
		cout<<ans<<'\n';
	}
}
