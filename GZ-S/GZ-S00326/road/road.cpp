//GZ-S00326 贵阳市新世界学校 王正彭 
#include<bits/stdc++.h>
using namespace std;
int fa[10005];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	priority_queue<pair<int,pair<int,int>>>q;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push(pair<int,pair<int,int>>{-w,u,v});
	} 
	int cnt=0,ans=0;
	while(cnt!=n-1)
	{
		int u=q.top().second.first;
		int v=q.top().second.second;
		int w=0-q.top().first;
		q.pop();
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			cnt++;
			ans+=w;
			fa[u]=fu;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
