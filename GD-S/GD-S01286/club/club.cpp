#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
int n;
int a[N][3];
vector<int> chose;
int maxn = 0;

void solve(int num)
{
	if(num > n)
	{
		int b[4] = {0, 0, 0, 0};
		int i = 1;
		int sum = 0;
		for(int v : chose)
		{
			sum += a[i][v];
			b[v]++;
			if(b[v] > n/2) return ;
			i++;
		}
		maxn = max(maxn, sum);
		return ;
	}
	for(int i = 1; i <= 3; i++)
	{
		chose.push_back(i);
		solve(num+1);
		chose.pop_back();
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		maxn = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
			}
		}
		solve(1);
		cout << maxn << endl;
	}
	return 0;
}
