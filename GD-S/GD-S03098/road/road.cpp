#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[100005],ans=1e18,c[100005];
int a[11][100005],b[11][100005];
bool vis[200005];
struct node{int from,to,len;}eg[1000005];
bool cmp(node a,node b){
	return a.len<b.len;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		eg[i]={u,v,w};
	}
	bool fl=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0)fl=0;
		for(int j=1,x;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]!=0)fl=0;
		}
	}
	if(fl){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;++i)vis[i]=1;
	sort(eg+1,eg+m+1,cmp);
	for(int opl=0;opl<=(1<<k)-1;++opl){
		int sum=0,ge1=1;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=k;++i)
			for(int j=1;j<=n;++j)
				b[i][j]=a[i][j];
		for(int i=1;i<=k;++i)
			if((opl>>i-1)&1)
				vis[i+n]=1,sum+=c[i];
			else vis[i+n]=0;
		for(int i=1;i<n;++i){
			int u=eg[i].from,v=eg[i].to;
			int yu=u,yv=v;
			u=find(u);v=find(v);
			fa[u]=v;
			int bian=eg[i].len;
			for(int j=1;j<=k;++j)
				if(vis[j+n]){
					bian=min(bian,b[j][u]+b[j][v]);
				}
			sum+=bian;
			for(int j=1;j<=k;++j)
				if(vis[j+n])
					b[j][v]=min(b[j][v],b[j][u]);
		}
//		for(int i=1;i<=k;++i)cout<<vis[i+n];
//		cout<<'\n'<<sum<<'\n';
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
