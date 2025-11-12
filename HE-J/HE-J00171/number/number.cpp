#include<bits/stdc++.h>
using namespace std;

int a[1005], n;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 1005; i++)
	{
		cin >> a[i];
		n++;
	}
	sort (a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) cout << a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
