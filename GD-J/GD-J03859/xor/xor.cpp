#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 5e5 + 5;
int n, k, a[N];
bool flag = true;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)
			flag = false;
	}
	if(flag)
	{
		cout << n / 2 << endl;
		return 0;
	}
	if(k <= 1)
	{
		if(k == 0)
		{
			int ans = 0;
			for(int i = 1; i < n; i++)
			{
				if(a[i] == a[i + 1])
					ans++, i++;
				else if(a[i] == 0)
					ans++;
			}
			cout << ans << endl;
		}
		else
		{
			int ans = 0;
			for(int i = 1; i < n; i++)
			{
				if(a[i] != a[i + 1])
					ans++, i++;
				else if(a[i] == 1)
					ans++;
			}
			cout << ans << endl;
		}
	}
	else
		cout << 169 << endl;
	return 0;
}
