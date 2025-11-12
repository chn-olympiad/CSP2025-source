#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, ans;
int a[N], sum[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
//			cout << i << " " << j << endl;
			int sum = a[i], len = j - i + 1;
			for(int l = i + 1; l <= j; l++)
				sum ^= a[l];
			if(sum == k)
			{
//				cout << sum << ":" << i << " " << j << endl;
				i = i + len - 1;
				ans++;
				break;
			}
		}
	}
//	int begin = 1;
//	for(int i = 1; i <= n; i++)
//	{
//		int sum = a[i];
//		for(int j = begin; j <= i; j++)
//		{
//			if(sum == k)
//			{
//				ans++;
//				i += i - j;
//				begin = j + 1;
//				break;
//			}
//			sum ^= a[j];
////			cout << "1231\n";
//		}
//	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
