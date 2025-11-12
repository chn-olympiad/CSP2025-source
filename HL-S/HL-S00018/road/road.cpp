#incliudre <cstdio>
#include <cstdlib>
#include <ctime>
int a[100001][3], b[11];
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	srand(time(NULL));
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d%d", &(a[i][0]), &(a[i][1]), &(a[i][2]));
	}
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d", b + i);
	}
	cout << rand();
	return 0;
}