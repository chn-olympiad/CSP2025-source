#include <bits/stdc++.h>
using namespace std;

long long n, k, a[500005], cnt_1, cnt_0, ans;
bool A = 1;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		if (a[i] == 0) A = 0, cnt_0 ++;
		else cnt_1 ++;
		if (a[i] == k) ans ++;
	}
	
	if (n <= 2)
	{
		if (n == 1) cout << 0;
		else cout << 1;
	}
	else if (k <= 1)
	{
		if (k == 0 && A) cout << n / 2;//A
		else//B
		{
			if (k == 1) cout << cnt_1;
			else
			{
				for (int i = 1; i < n; ++ i)
					if (a[i] == a[i+1]) cnt_0 ++, i ++;
					
				cout << cnt_0;
			}
		}
	} else {
		cout << ans;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
