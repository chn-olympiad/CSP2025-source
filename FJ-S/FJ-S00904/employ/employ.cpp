#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m;
vector<int> p;
int a[N], c[N];
bool st[N];
int ans = 0;
int check()
{
	int tot = 0, cnt = 0;
	for(int i = 0;i < n;i ++)
	{
		if(tot >= c[p[i]])
			tot ++;
		else if(a[i + 1] == 0)
			tot ++;
		else cnt ++;
	}
	if(cnt >= m) return 1;
	else return 0;
}
void dfs(int x)
{
	if(x == n + 1)
	{
		ans += check();
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(!st[i])
		{
			p.push_back(i);
			st[i] = 1;
			dfs(x + 1);
			p.pop_back();
			st[i] = 0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		char op;
		cin >> op;
		a[i] = op - '0';
	}
	for(int i = 1;i <= n;i ++)
		cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
