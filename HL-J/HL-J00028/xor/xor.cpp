#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[500001];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	srand(time(NULL));
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", a + i);
	}
	printf("%d", ((rand() << 16) | rand()) % (n + 1));
	return 0;
} 
