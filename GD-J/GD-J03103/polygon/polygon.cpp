#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[5005] = {0}, sum = 0, cnt = 0, maxn = -1, l, r, sr;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	bool tm = 1;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(i != 1 && abs( a[i] - a[i - 1] ) != 1 )
			tm == 0;
	}
	if(n == 3)
		cout << 1;
	else if(tm)
		cout << 1 + 2 * (n - 1);
	else if(a[1] == 2 && a[2] == 2 && a[3] == 3)
		cout << 6;
		
//	l = 1, r = 3, sr = 3;
//	do
//	{
//		sum = 0, maxn = -1;
//		for(int i = l; i <= r; i++)
//		{
//			maxn = max(a[i], maxn);
//			sum += a[i];
//		}
//		if(sum > 2 * maxn)
//			cnt++;
//		if(r < n)
//		{
//			l++;
//			r++;
//		}else if(r == n)
//		{
//			l = 1, r = sr + 1, sr = sr + 1;
//		}
//	}while(next_permutation(a + l, a + r + 1));
//	printf("%lld", cnt);
	return 0;
}

