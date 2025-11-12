#include <cstdio>

const int N = 500007;

int n, k, ans;
int a[N], rec;

int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]);
	rec = 1;
	for (int i = 1; i <= n; i ++)
	{
		int Xor = 0;
		for (int j = i; j >= rec; j --)
		{
			Xor ^= a[j]; 
			if (Xor == k)
			{
				ans ++;
				rec = i + 1;
				break;
			}
		}
	}
	printf ("%d", ans);
}
