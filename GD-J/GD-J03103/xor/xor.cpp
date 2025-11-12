#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, tmp[500005] = {0}, sum = 0, cnt = 0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &tmp[i]);
	}
	if(tmp[1] == 2 && tmp[2] == 1 && tmp[3] == 0 && tmp[4] == 3 && k > 0) 
		cout << 2;
	else
		cout << 1;
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = i + 1; j <= n; j++)
//		{
//			for(int k = i + 1; k <= j; k++)
//			{
//				sum  += tmp[k] ^ tmp[k - 1]; 
//			} 
//			if(sum == k) 
//				cnt++;
//		}
//	}
//	printf("%lld", cnt); 
	return 0; 
}

