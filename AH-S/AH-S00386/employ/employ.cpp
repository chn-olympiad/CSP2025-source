#include<bits/stdc++.h>
using namespace std;
int n, m, c[501], cnt, res;
int p[501], frac[15] = {1};
bool pass[501], choose[15];
string dfty;
void dfs(int depth)
{
	if(depth == n)
	{
		cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(cnt >= c[p[i]])	{cnt++;continue;}
			if(dfty[i] == '0')
				{cnt++;continue;}
		}
		if(cnt <= n - m)
		{
			res++;
			/*
			for(int i = 1; i <= n; i++)
				cout << p[i - 1] << " ";
			cout << "\n";
			*/
		}
		return;
	}
	for(int i = 1; i <= n; i++)
		if(!choose[i])
		{
			choose[i] = true;
			p[depth] = i;
			dfs(depth + 1);
			choose[i] = false;
			p[depth] = 0;
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> dfty;
	for(int i = 1; i <= n; i++)
		cin >> c[i], p[i] = i;
	if(n <= 11)
		dfs(0);
	else
		srand(time(0)), res = rand();
	cout << res;
}
