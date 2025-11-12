#include <bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,m,k;
long long ans=0x3f3f3f3f3f3f3f3f,res=0;
bool vis[maxn],build[11];
vector<pair<int,int>> t[maxn+11];

struct Node{
	int val;
}T[11];

void dfs(int u,int f,int st) {
	vis[u]=true;
	if(st==n) {
		ans=min(ans,res);
	}
	for(auto v : t[u]) {
		int x=v.first,y=v.second;
		if(vis[x]) continue;
		res+=y;
		if(x>n){
		    if(!build[x]) {
		    	res+=T[x-n].val;
			    build[x-n]=true;
			    dfs(x,u,st);
			    res-=T[x-n].val;
			}else dfs(x,u,st);
		}else dfs(x,u,st+1);
		vis[x]=false;
		res-=y;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++) {
		int va,s,w;
		scanf("%d",&va);
		T[i].val=va;
		for(int j=1;j<=n;j++) {
			scanf("%d",&w);
			t[i+n].push_back({j,w});
			t[j].push_back({i+n,w});
		}
	}
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
