#include<bits/stdc++.h>
using namespace std;

int a[5005], n, k, cnt = 0;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0) cnt++;
		}
		cout << cnt << endl;
	}
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 1) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
