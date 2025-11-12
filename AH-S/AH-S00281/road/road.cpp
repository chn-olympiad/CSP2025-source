#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[15][10005],ans=0x3f3f3f3f,price[10005],sum;
struct pri{
	int v,w;
};
vector<pri> g[10005];
vector<pri> co[10005];
vector<int> g1[10005];
bool vis[10005],vis1[10005];
bool check(int pos){
	bool f=false;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			f=true;
			break;
		}
	}if(!f){
		return true;
	}for(auto ed:g1[pos]){
		if(!vis[ed]){
			vis[ed]=true;
			return check(ed);
		}
	}return false;
}void dfs(int pos){
	if(sum>=ans){
		return ;
	}memset(vis,false,sizeof(vis));
	if(check(1)){
		ans=min(ans,sum);
		return ;
	}for(auto ed:g[pos]){
		if(!vis1[ed.v]||price[ed.v]>price[pos]+ed.w){
			vis1[ed.v]=true;
			int f=price[ed.v];
			price[ed.v]=price[pos]+ed.w;
			sum+=ed.w;
			dfs(ed.v);
			sum-=ed.w;
			price[ed.v]=f;
			vis1[ed.v]=false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		g[x].push_back(pri{y,z});
		g[y].push_back(pri{x,z});
	}for(int i=1,x;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}for(int j=1;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				g[i].push_back(pri{k,a[i][j]+a[i][k]+x});
			}
		}
	}dfs(1);
	cout<<ans;
	return 0;
}
