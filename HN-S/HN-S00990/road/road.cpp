#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[15][100005],fa_a[10005],fa[20005],ans=INT_MAX,sum;
bool vis[10005];
struct node{
	int u,v,w;
}edge_a[2000005],edge[200005],edge_b[10005];
bool cmp(node M1,node M2){
	return M1.w<M2.w;
}
int find_a(int x){
	if(fa_a[x]==x)return x;
	return fa_a[x]=find_a(fa_a[x]);
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int f(){
	int sum1=n-1,sum2=0,cnt1=n,cnt2=0;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			cnt1++;
			for(int j=1;j<=n;j++)edge[++sum1]={cnt1,j,a[i][j]};
		}
	}
	for(int i=1;i<=cnt1;i++)fa[i]=i;
	sort(edge+1,edge+sum1+1,cmp);
//	cout<<cnt1<<' '<<sum1<<'\n';
//	for(int i=1;i<=sum1;i++)cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<'\n';
//	cout<<'\n';
	for(int i=1;i<=sum1;i++){
		int u=find(edge[i].u),v=find(edge[i].v),w=edge[i].w;
		if(u!=v){
//			cout<<edge[i].u<<' '<<edge[i].v<<' '<<w<<'\n';
			fa[u]=v;
			cnt2++;
			sum2+=w;
		}
		if(cnt2==cnt1-1)break;
	}
	for(int i=1;i<n;i++)edge[i].u=edge_b[i].u,edge[i].v=edge_b[i].v,edge[i].w=edge_b[i].w;
	return sum2;
}
void dfs(int t,int tot){
	if(t>k){
//		for(int i=1;i<=k;i++)if(vis[i])cout<<i<<' ';
//		cout<<'\n';
//		cout<<x<<' '<<tot<<'\n'<<'\n';
		ans=min(ans,f()+tot);
		return;
	}
	vis[t]=1;
	dfs(t+1,tot+a[t][0]);
	vis[t]=0;
	dfs(t+1,tot);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge_a[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>a[i][j];
	sort(edge_a+1,edge_a+m+1,cmp);
	for(int i=1;i<=n;i++)fa_a[i]=i;
	for(int i=1;i<=m;i++){
		int u=find_a(edge_a[i].u),v=find_a(edge_a[i].v);
		if(u!=v){
			fa_a[u]=v;
			edge[++sum]=(node){edge_a[i].u,edge_a[i].v,edge_a[i].w};
			edge_b[sum]=(node){edge_a[i].u,edge_a[i].v,edge_a[i].w};
		}
		if(sum==n-1)break;
	}
//	cout<<'\n';
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
