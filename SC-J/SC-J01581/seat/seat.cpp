# include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int a[N], k;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m; k = n * m;
	for(int i = 1;i <= k;i ++ ) cin >> a[i];
	int tmp = a[1];
	sort(a + 1, a + k + 1), reverse(a + 1, a + k + 1);
	for(int i = 1;i <= k;i ++ )
	{
		if(a[i] == tmp)
		{
			int t = (i - 1) / n + 1;
			if(t & 1)
			{
				int q = i - (t - 1) * n; 
				cout << t << ' ' << q;
			}
			else
			{
				int q = (n - (i - (t - 1) * n) + 1);
				cout << t << ' ' << q;
			}
			return 0;
		}
	}
	
	return 0;
}