#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int v,w;
};
vector<Node>p[1000001];
bool vis[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int  ans=0;
	if(k==0){
		for(int i=1,u,v,w;i<=m;i++) {
		 cin>>u>>v>>w;
		  p[u].push_back({v,w});
		  p[v].push_back({u,w});
		  ans+=w;}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

