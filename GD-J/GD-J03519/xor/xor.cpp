#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : 1) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n ,k;
const int N = 2e6 + 10;
int a[N] ,cnt[N] ,sum[N];

int main()
{
	freopen("xor.in" ,"r" ,stdin);
	freopen("xor.out" ,"w" ,stdout);
	n = read() ,k = read();
	
	for (int i = 1;i <= n;i++) a[i] = read() ,sum[i] = sum[i - 1] ^ a[i];
	
	int now = 0 ,ans = 0;
	cnt[0]++;
	for (int i = 1;i <= n;i++)
	{
		int tar = sum[i] ^ k;
		if (cnt[tar])
		{
			while (now < i) cnt[sum[now++]]--;
			ans++;
		}
		cnt[sum[i]]++;
	}
	
	printf("%d\n",ans);
	
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1


*/
