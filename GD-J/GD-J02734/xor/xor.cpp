#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int n , m , a [N] , pre = 1 , ans;
signed main()
{
		freopen ("xor.in" , "r" , stdin);
		freopen ("xor.out" , "w" , stdout);
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			scanf ( "%lld" , &a [i]);
		for (int i = 1; i <= n; i++)
		{
			if (a [i] == m)
			{
				ans++;
				pre = i + 1; 
			} 	
			else 
			{
				int x = a [i];
				for (int j = i - 1; j >= pre; j--)
				{
					x ^= a [j];
					if (x == m)
					{
						ans++;
						pre = i + 1; 
						break;
					}
				}
			}
		}
		cout << ans;	
		return 0;
}

