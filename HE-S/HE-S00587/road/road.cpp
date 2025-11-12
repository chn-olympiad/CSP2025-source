#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN=4e6+10,NAXN=2e5+10;
int a[15][NAXN];
int cnt,nxt[MAXN],to[MAXN],val[MAXN],hand[MAXN];
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=hand[u];
	hand[u]=cnt;
}
priority_queue< pair<int,int> > q;
int vis[NAXN];
int c[15];
int get_tree(int s){
	int ans=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		int w=q.top().first;
		q.pop();
		if(vis[u]==1) continue;
		ans-=w;
		
		vis[u]=1;
		for(int i=hand[u];i;i=nxt[i]){
			int v=to[i];
			int w=val[i];
			q.push(make_pair(-w,v));
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(v,u,w);
		add(u,v,w);
	}
	long long cnt=get_tree(1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				add(n+i,j,a[i][j]);
				add(j,n+i,a[i][j]);
			}
		}cnt=max(cnt,(long long)get_tree(1));
	}
	cout<<cnt;
	return 0;
}
