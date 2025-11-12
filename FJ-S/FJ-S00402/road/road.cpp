#include <bits/stdc++.h>
using namespace std;
int n,m,k,co[15][10005],flag,ans,mina=0x7fffffff;
int vis[10005],dis[10005];
struct edge{
	int v,w;
};
vector<edge> e[10005];

void dfs(int x,int cnt){
	if(cnt==n){
		mina=min(mina,ans);
		return;
	}
	for(auto it:e[x]){
		if(!vis[it.v]){
			vis[it.v]=1;
			ans+=it.w;
			dfs(it.v,cnt+1);
			ans-=it.w;
			vis[it.v]=0;
		}
	}
}

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	for(int i=1;i<=m;i++){
		sort(e[i].begin(),e[i].end(),cmp);
	}
	/*
	for(int i=1;i<=m;i++){
		cout << i << ":\n";
		for(auto it:e[i]){
			cout << it.v << " " << it.w << endl;
		}
	}
	*/
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&co[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) vis[i]=1,dfs(i,1),vis[i]=0;
	}
	cout << mina;
	return 0;
} 
