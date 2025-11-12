#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 5e5+5;
int n, k;
int a[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", a + i);
	int ans = 0;
	if(k == 0)
	{
		rep(i, 1, n)
		{
			if(i > 1 && a[i] == 1 && a[i - 1] == 1) ans++, i++;
			ans += (a[i] == 0);
		}
	}
	else if(k == 1)
	{
		rep(i, 1, n) ans += (a[i] == 1);
	}
	printf("%d", ans);
	return 0;
}
