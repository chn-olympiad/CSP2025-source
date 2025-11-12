#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e3+5;
int n,m,k;
int T;
struct node{
	int to,dis;
};
vector<node>a[N];
struct bian{
	int u,v,w;
}p[N];
int f[N];
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
bool cmp(bian a,bian b){
	return a.w<b.w;
}
int c[N];
int use[15][N];
int mx;
signed main(){
	//ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(node{v,w});
		a[v].push_back(node{u,w});
		p[i]=bian{u,v,w};
		mx=max(mx,w);
	}
	if(k==0){
		long long ans=0;
		sort(p+1,p+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=p[i].u,v=p[i].v,w=p[i].w;
			if(find(u)==find(v))continue;
			f[find(u)]=find(v);
			ans+=w;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>use[i][j];
	}
	int cnt=m;
	for(int i=n+1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(use[i][j]<mx)p[++cnt]={n+i,j,use[i][j]};
		}
	}
	long long ans=0;
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int u=p[i].u,v=p[i].v,w=p[i].w;
		if(find(u)==find(v))continue;
		f[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
}
/*
5 6 0
1 3 1
3 2 3
1 5 2
2 4 4
3 5 6
4 5 5
*/
