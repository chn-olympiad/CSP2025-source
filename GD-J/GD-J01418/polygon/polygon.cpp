#include<bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n;
int a[N];
int maxn = 0;
vector<int> ch;
long long res = 0;

void spe()
{
	long long ans = 0;
	for(int i = 3; i <= n; i++)
	{
		long long sum = 1;
		for(int j = i+1; j <= n; j++)
		{
			sum *= j;
			sum %= mod;
		}
		ans += sum;
		ans %= mod;
	}
	cout << ans;
}
void solve(int num, int chose)
{
	if(num > n)
	{
		if(chose < 3) return ;
		maxn = 0;
		long long sum = 0;
		for(int v : ch)
		{
			sum += a[v];
			maxn = max(maxn, a[v]);
		}
		if(sum > maxn * 2)
		{
			res++;
//			for(int v : ch)
//			{
//				cout << v << " ";
//			}
//			cout << endl;
		}
		res %= mod;
		return ;
	}
	ch.push_back(num);
	solve(num+1, chose+1);
	ch.pop_back();
	solve(num+1, chose);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if(maxn == 1)
	{
		spe();
	}
	else
	{
		solve(1, 0);
		cout << res << endl;
	}
	return 0;
}
