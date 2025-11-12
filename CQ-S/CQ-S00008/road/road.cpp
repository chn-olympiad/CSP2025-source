#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,k,i,j,l,a[15],b[15][N],c[N],f[N],x,op,ans=1e18;
int u,v,w;
bool p[15];
vector<pair<int,int>>e[N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void bfs(int n2){
	priority_queue<pair<int,pair<int,int>>>q;
	pair<int,pair<int,int>>t;
	int u,v,w,i,x,y,lp=n2;
	for(i=n+1;i<=n2;i++) lp-=(c[i]<=1);
	for(i=1;i<=n2;i++) c[i]=0;
	for(i=1;i<=n;i++){
		for(auto t:e[i]){
			u=i,v=t.first,w=t.second;
			q.push({-w,{u,v}});
		}
	}
	for(i=1;i<=n2;i++) f[i]=i;
	while(!q.empty()&&lp>1){
		t=q.top();q.pop();
		u=t.second.first,v=t.second.second,w=-t.first;
		x=find(u),y=find(v);
		if(x==y) continue;
		f[x]=y,lp--,op+=w,c[u]++,c[v]++;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
	}
	for(i=1;i<=k;i++){
		cin>>a[i];
		for(j=1;j<=n;j++) cin>>b[i][j];
	}
	op=0;bfs(n);
	ans=min(ans,op);
	for(i=1;i<=k;i++){
		x+=a[i];
		for(j=1;j<=n;j++) e[j].push_back({n+i,b[i][j]});
		op=x;bfs(n+i);
		for(j=1;j<=i;j++)
			if(c[n+j]<=1) op-=a[j];
		ans=min(ans,op);
	}
	cout<<ans;
	return 0;
}
