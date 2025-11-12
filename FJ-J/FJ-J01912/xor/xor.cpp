#include <bits/stdc++.h>
using namespace std;
    int n;
	long long k, a[500005], sum, num, length;
long long yiyuhe(long long p, long long q)
{
	num = 0;
	for(int c = p; c <= q; c++)
		if(a[c] == 0)
		    num++;
	for(int c = p; c <= q; c++)
	    sum += a[c];
	return sum / num;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	    cin >> a[i];
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= n; i++)
		    length = max(length, yiyuhe(i, j));
	cout << length;
	return 0;
}
