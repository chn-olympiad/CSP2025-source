#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
using namespace std;
const int N = 1e4 + 10;
int n,m,k,sum,ans,f[N],c[11][N];
bool bld[11];
vector <tuple <int,int,int>> edg;
void ini()
{
	for(int i = 1;i < N;i++)
		f[i] = i;
}
int fa(int x)
{
	return x == f[x] ? x : f[x] = fa(f[x]);
}
void kruskal()
{
	ini();
	sort(edg.begin(),edg.end());
	int cnt = 0;
	for(auto x : edg)
	{
		int u,v,w,f1,f2;
		tie(u,v,w) = x;
		f1 = fa(u),f2 = fa(v);
		if(f1 != f2)
		{
			f[f1] = f2;
			sum += w;
			cnt++;
		}
		if(cnt == n - 1)
			break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= m;i++)
	{
		cin >> u >> v >> w;
		edg.push_back(make_tuple(u,v,w));
	}
	kruskal();
	for(int i = 1;i <= k;i++)
	{
		bool flag = false;
		cin >> c[i][0];
		if(c[i][0])
			flag = true;
		else
			bld[i] = true;
		for(int j = 1;j <= n;j++)
		{
			cin >> c[i][j];
			if(c[i][j])
				flag = true;
		}
		if(!flag)
		{
			cout << 0;
			return 0;
		}
	}
	cout << sum;
	return 0;
}

