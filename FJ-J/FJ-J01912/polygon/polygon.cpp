#include <bits/stdc++.h>
using namespace std;
int n, a[5005], sum, num;
const long long MOD = 998244353;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{ 
	    cin >> a[i];
	    sum += a[i];
	} 
	for(int i = 1; i <= n; i++)
	{
        for(int j = 2; j <= n; j++)
            for(int k = 3; k <= n; k++)
            {
            	if(max(a[i], max(a[j], a[k])) * 2 <= sum && j != k)
				    num++;
			}
	}
	cout << num % MOD;
	return 0;
}
