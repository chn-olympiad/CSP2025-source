#include <bits/stdc++.h>
#define endl putchar('\n')
#define int long long
using namespace std;
int read()
{
	char ch = getchar();
	int sum = 0;
	for (ch;ch < '0' || ch > '9';ch = getchar());
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum;
}
void write(int x)
{
	if (x < 10) return putchar(x + '0'), void();
	write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 5e5 + 5;
int n, k, a[N], sum[N], ans;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1;i <= n;i++) a[i] = read(), sum[i] = sum[i - 1] ^ a[i];
	for (int l = 1, r = 1;l <= n;)
	{
		unordered_map<int, bool> mp;
		mp[0] = 1;
		while (r <= n)
		{
			if (a[r] == k) {ans++; break;}
			int now = sum[r] ^ sum[l - 1];
			if (mp[now ^ k]) {ans++; break;}
			else mp[now] = 1;
			r++;
		}
		l = ++r;
	}
	write(ans);
	return 0;
}
/*
And you don't seem to understand
A shame at like you honest man
And no one's meant to hurt you
And no one's meant my heart
And the way about that we both share
I am falling
I am fading
I am downing
Help me to breathe
            ¡ª¡ª¡¶duvet¡· boa
*/
