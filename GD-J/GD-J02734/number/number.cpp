#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
string s;
int a [N] , sum;
bool cmp (int b1 , int b2)
{
	return b1 > b2;
}
signed main()
{
		freopen ("number.in" , "r" , stdin);
		freopen ("number.out" , "w" , stdout);
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s [i] >= '0' && s [i] <= '9')
				a [++sum] = s [i] - '0';
		}
		sort (a + 1 , a + sum + 1 , cmp);
		for (int i = 1; i <= sum; i++)
			printf ("%lld" , a [i]);
		return 0;
} 
