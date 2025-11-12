#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct node{
	int u,v,w;
};
node a[maxn];
int n,m,k;
bool cmp(node x,node y){
	return x.w,y.w;
}
int vis[10005];
vector<node>V;
int sz[10005];
int b[15];
struct edge{
	int v,w;
}c[15][10005],d[15][10005];
bool cmp2(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
//		cin>>u>>v>>w[i];
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
//	cout<<1;
	int cnt=n-1;
	int i=1;
	while(cnt){
		int u=a[i].u,v=a[i].v;
//		cout<<u<<' '<<v<<cnt<<endl;
		if(vis[u]==0||vis[v]==0){
			V.push_back({min(u,v),max(u,v),a[i].w});
			cnt--;
			vis[u]=1;
			vis[v]=1;
			sz[u]++;
			sz[v]++;
//			cout<<u<<' '<<v<<endl;
		}
		i++;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j].w);
			d[i][j]=c[i][j];
			c[i][j].v=j;
		}
		sort(c[i]+1,c[i]+1+n,cmp2);
	}
	long long ans=0;
	for(int i=0;i<n-1;i++){
		int u=V[i].u;
		int v=V[i].v;
		long long w=V[i].w;
		long long mn=2e17+5;
		long long tmp;
		if(sz[u]==1){
			tmp=0;
			for(int j=1;j<=k;j++){
				tmp=b[j]+d[j][v].w;
				int x=1;
				while(c[j][x].v==u)x++;
				tmp+=c[j][x].w;
			}
			mn=min(mn,tmp);
		}
		else if(sz[v]==1){
			tmp=0;
			for(int j=1;j<=k;j++){
				tmp=b[j]+d[j][v].w;
				int x=1;
				while(c[j][x].v==u)x++;
				tmp+=c[j][x].w;
			}
			mn=min(mn,tmp);
		}
		else{
			for(int j=1;j<=k;j++){
				tmp=b[j]+d[j][u].w+d[j][v].w;
				mn=min(mn,tmp);
			}
		} 
		ans+=min(mn,w);
//		cout<<i;
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 1 3 0 4
*/
