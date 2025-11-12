#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int to,len;
};
int n,m,k;
int change[15],bridge[15][10004];
int minn[10004],fath[10004];
bool changed[15];
int rt[10004],ans;
bool special = 1;
vector <node> pict[10004];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		pict[u].push_back({v,w});
		pict[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> change[i];
		if(change[i]) special = 0;
		for(int j = 1;j <= n;j++)
		{
			cin >> bridge[i][j];
			minn[j] = 0x3f3f3f3f;
			if(bridge[i][j]) special = 0;
		}
	}
	if(special)
	{
		cout << 0;
		return 0;
	}
	minn[n + 1] = 0x3f3f3f3f;
	minn[1] = 0;
	for(int i = 1;i <= n;i++)
	{
		int now = n + 1;
		for(int j = 1;j <= n;j++)
		{
			if(minn[j] < minn[now]) now = j;
		}
		for(auto j : pict[now])
		{
			if(minn[j.to] > minn[now] + j.len)
			{
				minn[j.to] = minn[now] + j.len;
				fath[j.to] = now;
			}
		}
	}
	for(int i = 2;i <= n;i++)
	{
		int price = minn[i] - minn[fath[i]];
		int lineto = 0,midturn = 0;
		for(int j = 1;j <= n;j++)
		{
			for(int t = 1;t <= k;t++)
			{
				if(!lineto || !midturn)
				{
					lineto = j;
					midturn = t;
				}
				if(change[t] + bridge[t][i] + bridge[t][j] - (rt[j] == t) * (bridge[t][j]) - changed[t] * change[t] < change[midturn] + bridge[midturn][i] + bridge[midturn][lineto] - (rt[lineto] == midturn) * bridge[midturn][lineto] - changed[midturn] * change[midturn])
				{
					lineto = j;
					midturn = t;
				}
			}
		}
		if(change[midturn] + bridge[midturn][i] + bridge[midturn][lineto] - (rt[lineto] == midturn) * bridge[midturn][lineto] - changed[midturn] * change[midturn] <= price)
		{
			ans += change[midturn] + bridge[midturn][i] + bridge[midturn][lineto] - (rt[lineto] == midturn) * bridge[midturn][lineto] - changed[midturn] * change[midturn];
			changed[midturn] = 1;
			rt[lineto] = midturn;
		}
		else ans += price;
	}
	cout << ans;
}
