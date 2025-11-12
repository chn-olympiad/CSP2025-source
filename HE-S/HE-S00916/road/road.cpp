//May all the beauty be blessed.
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k;
int fa[11000],d[15][10100],c[15];
int ans=1e12;
int findl(int x){
	return fa[x]==x?x:fa[x]=findl(fa[x]);
}

struct edges{
	int u,v,val;
	bool operator<(const edges &aa) const{
		return val>aa.val;
	}
};
priority_queue<edges> op,p;

int kru(){
	int sum=0;
	while(p.size()){
		auto x=p.top();
		p.pop();
		if(findl(x.u)==findl(x.v)) continue;
		sum+=x.val;
		fa[findl(x.u)]=findl(x.v);
	}
	
	return sum;
}

vector<int> aa;
void dfs(int x,int s,int ss){
	if(x>k){
		p=op;
		for(auto i:aa){
			for(int j=1;j<=n;j++){
				p.push({i+n,j,d[i][j]});
			}
		}
		
		for(int i=1;i<=n+s;i++) fa[i]=i;
		ans=min(ans,kru()+ss);
		return;
	}
	
	dfs(x+1,s,ss);
	aa.push_back(x);
	dfs(x+1,s+1,ss+c[x]);
	aa.pop_back();
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		op.push({u,v,val});
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	dfs(1,0,0);
	
	cout<<ans;
}
/*

*/

