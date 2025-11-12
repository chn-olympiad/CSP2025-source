#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 10020;
vector<int> s[N], l[N];
long long d[N], fl[N];
int n, m, k, w[11];
bool f[12];

void DFS(int r)
{
	if (r > n && !f[r - n])
	{
		return;
	}
	for (int i = 0; i < s[r].size(); i++)
	{
		if (l[r][i] < fl[s[r][i]])
		{
			fl[s[r][i]] = l[r][i];
			DFS(s[r][i]);
		}
	}
}

void Init()
{
	fl[1] = 0;
	for (int i = 2; i <= n + k; i++)
	{
		fl[i] = 1145141919810;
	}
}

long long sum()
{
	long long ans = 0;
	for (int i = 2; i <= n; i++)
	{
		ans += fl[i];
	}
	for (int i = 1; i <= k; i++)
	{
		if (f[i])
		{
			ans += fl[n + i] + w[i];
		}
	}
	return ans;
}

void fnxt()
{
	int x = 1;
	for (; f[x]; x++)
	{
		f[x] = false;
	}
	f[x] = true;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int x, y, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> c;
		s[x].push_back(y);
		s[y].push_back(x);
		l[x].push_back(c);
		l[y].push_back(c);
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> w[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> c;
			s[n + i].push_back(j);
			s[j].push_back(n + i);
			l[n + i].push_back(c);
			l[j].push_back(c);
		}
		f[i] = false;
	}
	f[k + 1] = true;
	long long minans = 1145141145141919810, ans;
	for (; f[k + 1]; fnxt())
	{
		Init();
		DFS(1);
		ans = sum();
		cout << ans << endl;
		if (minans > ans)
		{
			minans = ans;
		}
	}
	cout << minans << endl;
	return 0;
}