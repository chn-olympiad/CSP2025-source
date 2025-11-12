#include <bits/stdc++.h>
using namespace std;
int a[500001];
int calc(int l, int r)
{
	if(l == r)
		return a[l];
	
	int res = a[l];
	for(int i = l+1; i <= r; i++)
		res ^= a[i];
	return res;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, l = 1, r = 1, ans = 0;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	while(true)
	{
		int res = calc(l, r);
		
		if(res == k)
		{
			//cout << l << " " << r << endl;
			ans++;
		}
		
		if(r == n)
		{
			if(l == n)
				break;
			l++;
			r = l;
		}
		else
			r++;
	}
	cout << ans;
	return 0;
}
