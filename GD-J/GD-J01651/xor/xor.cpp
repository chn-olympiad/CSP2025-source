#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int MAXN = 500005, MAXK = (2 << 20);
int a[MAXN];
int n, k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	int ans = 0;
	int sum = -1;
	for (int len = 1; len <= n; len++)
	{
		int t_ans = 0;
		for (int l = len; l <= n; l++)
		{
			for (int r = l; r <= n; r++)
			{
				if (sum == -1) sum = a[r];
				else sum ^= a[r];
				
	//			if (l == r && l == 4) cout << r << ' ' << a[r] << ';' << sum << "no\n";
				
				if (sum == k)
				{
					t_ans++;
					l = r;
					
	//				cout << sum << '*' << l << ' ' << r << endl;
					
					sum = -1;
	//				break;
				}
			}
		}
		ans = max(ans, t_ans);
	}
	
	cout << ans << endl;

	return 0;
}
/*
4 2
2 1 0 3

4 0
2 1 0 3


*/
