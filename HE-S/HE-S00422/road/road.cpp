#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 10;
int n,m,k;
struct node{
	int u,v,w;
};
bool operator< (node a,node b)
{
	return a.w<b.w;
}
vector<node> a;
int x[15][MAXN];
int dp[MAXN + 15][MAXN];
void f()
{
	//sort(a,a + n);
	for(int i = 0; i < n; i++)//起点
	{
		for(int j = i; j < n; j++)//终点
		{
			for(int k = i; k < j; k++)//分割点
			{

			}
		}
	}
}
int main()
{
	freopen("rood.in","r",stdin);
	freopen("rood.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a.push_back(node{u,v,w});
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			cin>>x[i][j];
		}
	}
	//f();
	return 0;
}
