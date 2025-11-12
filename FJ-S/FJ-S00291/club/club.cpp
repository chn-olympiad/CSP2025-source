#include <cstdio>
#include <cstring> 
#include <algorithm>

const int N = 1e5 + 7;

typedef long long ll;

int T, n, used[4];
int a[N][4], diff[N];
ll lar[N], too[N], ans, tot;

using namespace std;

void work ()
{
	ans = tot = 0;
	memset (lar, 0, sizeof (lar));
	memset (too, 0, sizeof (too));
	memset (diff, 0, sizeof (diff));
	memset (used, 0, sizeof (used)); 
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf ("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
	for (int i = 1; i <= n; i ++)
	{
		if (a[i][1] > a[i][2] && a[i][1] > a[i][3])
		{
			used[1] ++;
			lar[i] = 1;
		}
		if (a[i][2] > a[i][3] && a[i][2] > a[i][1])
		{
			used[2] ++;
			lar[i] = 2;
		}
		if (a[i][3] > a[i][1] && a[i][3] > a[i][2])
		{
			used[3] ++;
			lar[i] = 3;
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		sort (a[i] + 1, a[i] + 4);
		diff[i] = a[i][3] - a[i][2];
		ans += a[i][3];
	} 
	ll need = 0;
	for (int i = 1; i < 4; i ++)
		if (used[i] > n / 2)
		{
			need = i;
			break;
		}
	for (int i = 1; i <= n; i ++)
		if (lar[i] == need)
			too[++ tot] = diff[i];
	sort (too + 1, too + tot + 1);
	for (int i = 1; i <= used[need] - n / 2; i ++)
		ans -= too[i];
	printf ("%lld\n", ans); 
}

int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout); 
	scanf ("%d", &T);
	while (T --)
		work ();
	return 0; 
}
