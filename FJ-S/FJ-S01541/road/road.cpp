#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int n,m,k,f = 1,fa[114514];
vector<pair<pair<int,int>,int> > v;
vector<pair<int,int> > c[114514];
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	return a.second < b.second;
}
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y)
{
	x = find(x);
	y = find(y);
	fa[y] = x;
}
int judge(int x,int y)
{
	return find(x) == find(y);
}
signed main()
{
	FILE("road");
	ioimprove();
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		int u,vv,w;
		cin>>u>>vv>>w;
		v.push_back({{u,vv,},w});
	}
	for(int i = 1;i <= k;i++)
	{
		int x;cin>>x;if(x) f = 0;
		c[i].push_back({0,x});
		for(int j = 1;j <= n;j++) 
		{
			int y;
			cin>>y;
			c[i].push_back({j,y});
		}
	}
	if(f)
	{
		for(int i = 1;i <= k;i++)
		{
			int xxx = 0;
			for(int j = 0;j < c[i].size();j++)
				if(c[i][j].first == 0) xxx = c[i][j].first;
			for(int j = 0;j < c[i].size();j++)
				if(c[i][j].first != xxx) v.push_back({{xxx,i},c[i][j].second});	
		}
	}
	if(k == 0 || f)
	{
		sort(v.begin(),v.end(),cmp);
		int sum = 0;
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 0;i < v.size();i++)
		{
			if(judge(v[i].first.first,v[i].first.second)) continue;
			else unionn(v[i].first.first,v[i].first.second),sum += v[i].second;
		}
		cout<<sum;
	}
		
	
	return 0;
}

/*
不大想学 OI 了，这大概是人生中写的最后一道 OI 题吧，留个纪念。 
*/
