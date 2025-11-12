#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, r = 2;
	int answer = 0;
	while (l <= n)
	{
        if (a[l] == k)
		{
			answer++;
			l++;
			r++;
			continue;
		}
		int yh = a[l];
		while (r <= n)
		{
			yh = (yh ^ a[r]);
			if (yh == k)
			{
				answer++;
				l = r;
				break;
			}
			r++;
		}
		l++;
        r= l + 1;
	}
	cout << answer;
	return 0;
}
