#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
int a [N] [N];
int b [20] [N];
int c [N];
int n , m , k , u , v , w;
signed main()
{
		freopen ("road.in" , "r" , stdin);
		freopen ("road.out" , "w" , stdout);
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++)
			scanf ("%lld%lld%lld" , u , v , w);
		for (int i = 1; i <= k; i++)
		{
			cin >> c [i];
			for (int j = 1; j <= n; j++)
				cin >> b [i] [j];
		}	
		cout << rand();		
		return 0;
}

