#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int c, a[15];
bool city;
bool ro[105]={0};
bool vis[1000005]={0};

vector<int>map1[1000005];
vector<int>mp2[1000005];

int ans=INT_MAX;

void dft(int cod, int cost, int num)
{
	if(cod==n)
	{
		ans=min(ans, cost);
		return;
	}
	
	for(int i = 0; i < sizeof(map1[num]); i++)
	{
		if(vis[map1[num][i]==0])
		{
			vis[map1[num][i]]=1;
			dft(cod+1, cost+mp2[num][i], map1[num][i]);
			vis[map1[num][i]]=0;
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		map1[u].push_back(v);
		mp2[u].push_back(w);
		map1[v].push_back(u);
		mp2[v].push_back(w);
	}
	cin >> c;
	for(int i = 1; i <= k; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++)
	{
		map1[i].push_back(n+1);
		mp2[i].push_back(a[i]);
		map1[n+1].push_back(i);
		mp2[n+1].push_back(a[i]);
	}
	dft(0,0,1);
	cout << ans;
	return 0;
}


