#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn = 1e6 + 7;
struct Node
{
	int v,w;
};
vector<Node> G[maxn];
int jianshe[maxn];
int main()   
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v , w});
		G[v].push_back({u , w});
	}
	int flag = true;
	for(int i = m + 1;i <= k + m + 1;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			int x;
			cin >> x;
			if(j == m + 1)
			{
				jianshe[i] = x;
			}
			else
			{
				G[i].push_back({j , x});
				G[j].push_back({i , x});
			}
			if(x != 0)
			{
				flag = false;
			}
		}
	}
	if(flag == false)
	{
		cout << 0;
		return 0;
	}
	return 0;
}

