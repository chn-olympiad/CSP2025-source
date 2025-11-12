#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, tarr[(int)5e5 + 1];
ll k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int onum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> tarr[i];
		if (tarr[i] == 1)
			onum++;
	}
	if (k == 1)
		cout << onum;
	else
	{
		int ans = n - onum;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (tarr[i] == 1)
				cnt++;
			else
			{
				ans += cnt / 2;
				cnt = 0;
			}
		}
		ans += cnt / 2;
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
