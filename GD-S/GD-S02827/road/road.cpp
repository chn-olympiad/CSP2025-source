#include<bits/stdc++.h>
using namespace std;

struct r
{
	int u,v,w;
};
r road[1000010];
int n,m,k,u,v,w,ans,over[10010];
vector<int> vis[10010];
queue<int> q;
bool cmp(r x,r y)
{
	return x.w<y.w;

}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	sort(road+1,road+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		bool check=false;
		q.push(road[i].u);
		memset(over,0,sizeof(over));
		while(!q.empty())
		{
			int j=q.front();
			q.pop();
			for(auto i:vis[j])
			{
				if(over[i]==0)
				{
					q.push(i);
					over[i]=1;
					if(i==road[i].v) 
					{
						check=true;
						break;
					}
				}
				
			}
		}
		if(!check)
		{
			ans+=road[i].w;
			vis[road[i].v].push_back(road[i].u);
			vis[road[i].u].push_back(road[i].v);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
