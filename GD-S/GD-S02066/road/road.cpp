#include <bits/stdc++.h>
using namespace std;

struct node
{
	int to,val,id;
};
int n,m,k,u,v,w,ans;
int no[1000006];
bool is[1000006];
int l[10004];
vector<node>edge[10004];
vector<node>edge2[10004];
int c[10004];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge[u].push_back({v, w, i});
		edge[v].push_back({u, w, i});
	}
	for(int i = 1;i<=n;i++)
	{
		int mn = 1e9,id = 0;
		for(auto j:edge[i])
		{
			if(mn>j.val)
			{
				mn = j.val;
				id = j.id;
			}
		}
		for(auto j:edge[i])
		{
			if(j.id!=id)
			{
				no[j.id]++;
				if(no[j.id]>=2)
				{
					is[j.id] = 1;
				} 
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(auto j:edge[i])
		{
			if(!is[j.id])
			{
				ans+=j.val;
				edge2[i].push_back(j);
			}
		}
	}
	ans/=2;
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int i = 0;i<=n;i++)
			cin>>c[i];
		int sum = 0;
		for(auto j:edge2[i])
			if(j.val >= c[j.to])
				sum+=j.val-c[j.to];
		if(c[0] <= sum)
			l[i] = sum-c[0];
	}
	sort(l+1, l+n+1, cmp);
	for(int i = 1;i<=k;i++)
		ans-=l[i];
	cout<<ans;
	return 0;
}
