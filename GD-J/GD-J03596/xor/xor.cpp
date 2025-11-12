#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 * 2 + 200;
ll k, a[N], s[N];
int n, l = 1, cnt; 
int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w" , stdout);
	
	scanf ("%d%lld", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%lld", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if ( ( s[i] ^ s[l - 1] ) == k)
		{
			l = i + 1;
			cnt++;
		}
	}
	printf ("%d", cnt);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
