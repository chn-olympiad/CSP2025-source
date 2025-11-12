#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
vector<pair<int,int> > v[N];
int n,k,ans=LLONG_MAX,col[20],e[20][N],c[20];
bool vis[N];
int Mst(){
	int res=0,cnt=0;
	for(int i=0;i<=10015;++i) vis[i]=0;
	for(int i=1;i<=k;++i){
		if(col[i]==0) continue;
		res+=c[i];
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,1});
	while(!q.empty()){
		int y=q.top().first,x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1,res+=y;
		if(x<=10000) ++cnt;
		if(res>=ans) return LLONG_MAX;
		if(cnt==n) break;
		if(x<=10000){
			for(auto i:v[x]){
				if(vis[i.first]) continue;
				q.push({i.second,i.first});
			}
			for(int i=1;i<=k;++i){
				if(col[i]==0) continue;
				if(vis[i+10000]) continue;
				q.push({e[i][x],i+10000});
			}			
		}
		else{
			for(int i=1;i<=n;++i){
				if(vis[i]==1) continue;
				q.push({e[x-10000][i],i});
			}
		}
	}
	return res;
}
void dfs(int x){
	if(x==k+1){
		ans=min(ans,Mst());
		return ;
	}	
	if(c[x]==0) col[x]=1,dfs(x+1);
	else {
		col[x]=0;
		dfs(x+1);
		col[x]=1;
		dfs(x+1);		
	} 
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	cin >>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin >>x>>y>>z;
		v[x].push_back({y,z}),v[y].push_back({x,z});
	}
	for(int i=1;i<=k;++i){
		cin >>c[i];
		for(int j=1;j<=n;++j) cin >>e[i][j];
	}
	dfs(1);
	cout <<ans;
	return 0; 
} 
