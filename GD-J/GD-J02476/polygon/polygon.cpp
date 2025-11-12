#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mod 998244353

const int maxn = 5100;

int n, maxa, cnt1;
int a[maxn];

//int fact(int a, int b)
//{
//	int ans = 1;
//	for(int i = a; i >= a - b + 1; --i)
//	{
//		ans *= i;
//	}
//	return ans;
//}
//
//int fact2(int a)
//{
//	int ans = 1;
//	for(int i = 1; i <= a; ++i)
//	{
//		ans *= i;
//	}
//	return ans;
//}
//
//int comb(int a, int b)
//{
//	if(a == 1) return b;
//	if(a == b) return 1;
//	return fact(a, b) / fact2(b); 
//}

signed main()
{
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if(a[i] == 1) cnt1 ++;
		maxa = max(maxa, a[i]);
	}
	
	if(n < 3)
	{
		cout << "0\n";
		return 0;
	}
	else if(n == 3)
	{
		int tmp1 = a[1], tmp2 = a[2], tmp3 = a[3];
		int maxtmp = max(max(tmp1, tmp2), tmp3), sumtmp = tmp1 + tmp2 + tmp3;
		
		if(sumtmp <= 2 * maxtmp)
		{
			cout << "0\n";
			return 0;
		}
		else
		{
			cout << "1\n";
		}
	}
	
	else if(maxa == 0)
	{
		cout << "0\n";
		return 0;
	}
	
	else if(maxa == 1)
	{
		
	}
	return 0;
}
