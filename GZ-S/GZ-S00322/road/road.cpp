//GZ-S00322 北京师范大学贵阳附属中学 王明轩 
#define min2(a,b) (a<b?a:b)
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
vector<vector<pair<int,int> > >v(10010);
bool vis[10010];
int ans=0x3f3f3f3f3f;
void dfs(int x,int cnt,int sum){
	if(cnt==n){
		ans=min2(ans,sum);
		return;
	}
	vis[x]=true;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i].first])dfs(v[x][i].first,cnt+1,sum+v[x][i].second);
	}
	vis[x]=false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	for(int i=1;i<=n;i++)dfs(i,1,0);
	cout<<ans;
	return 0;
}
