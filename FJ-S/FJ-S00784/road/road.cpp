#include <bits/stdc++.h>
using namespace std;

struct stu
{
	int vi, wi;
	bool flag;
};
vector<stu> t[1000006];

struct stk
{
	int c;
	int a[10004];
}sk[11];

int main()
{
	//freopen("road.in", "r", stdin);
	//freopen("road.ans", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		t[u].push_back(stu{v, w, false});
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> sk[i].c;
		for (int j = 1;j <= n;j++)
		{
			cin >> sk[i].a[j];
		}
	}
	
	int ans = 0;
	
	
	cout << ans << endl;
	return 0;
}
