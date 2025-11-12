#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e5 + 10;
const int M = 2e6 + 10;
int n, k, a[N];
int sum[N], id[M], f[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	for(int i = 1;i <= M - 10; ++ i)
		id[i] = -1;
	
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n; ++ i)
		scanf("%d", &a[i]);
	for(int i = 1;i <= n; ++ i)
		sum[i] = sum[i - 1] ^ a[i];
	
	for(int i = 1;i <= n; ++ i)
	{
		f[i] = f[i - 1];
		int j = id[sum[i] ^ k];
		if(~j) f[i] = max(f[i], f[j] + 1);
		id[sum[i]] = i;
	}
	printf("%d\n", f[n]);
	return 0;
}
