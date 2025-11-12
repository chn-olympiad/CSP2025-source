#include<iostream>
#include<algorithm>
using namespace std;
const int Mod = 998244353;

long long n, a[5010], ans;
bool flg = true;
void dfs(long long now, long long len, long long cnt, long long sum)
{
	if(len - cnt > n - now)
	{
		return;
	}
	if(cnt == len)
	{
		if(sum > a[now] * 2)
		{
			ans = (ans + 1) % Mod;
		}
		return ;
	}
	for(int i = now + 1; i <= n; i++)
	{
		dfs(i, len, cnt + 1, sum + a[i]);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) flg = false;
	}
	if(flg)
	{
		for(int i = 3; i <= n; i++)
		{
			for(int j = 1; j <= n - i + 1; j++)
			{
				ans += (((1 + n - (j + i - 2)) * (n - (j + i - 2) % Mod) % Mod) % Mod / 2) % Mod;
			}
		}
		cout << ans << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
//	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	for(int i = 3; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dfs(j, i, j, a[j]);
		}
	}
	cout << ans << endl;
	return 0;
}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for(int i = 1; i <= 500; i++)
//	{
//		cout << 1 << ' '
//	}
//}
