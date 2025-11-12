#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int T, n, cnt[4], mxcnt;
struct s
{
	int id;
	ll i;
}t[4];
bool cmp(s s1, s s2)
{
	return s1.i < s2.i;
}
ll b[4][N], ans;
ll read()
{
	char c = ' ';
	ll res = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	return res;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--)
	{
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		n = read();
		//printf("\n");
		for(int x = 1; x <= n; x++)
		{
			//a[x][1] = read(), a[x][2] = read(), a[x][3] = read();
			t[1].i = read(), t[2].i = read(), t[3].i = read();
			t[1].id = 1, t[2].id = 2, t[3].id = 3;
			sort(t + 1, t + 1 + 3, cmp);
			b[t[3].id][++cnt[t[3].id]] = t[3].i - t[2].i;
			ans += t[3].i;
			//printf("x = %d, %lld %lld %lld   %lld  %lld\n", x, t[1].i, t[2].i, t[3].i, b[t[3].id][cnt[t[3].id]], ans);
		}
		//printf("ans = %lld\n", ans);
		int mx = 0;
		for(int x = 1; x <= 3; x++) if(cnt[x] > n / 2) mx = x;
		if(mx)
		{
			//printf("cnt: %d %d %d\n", cnt[1], cnt[2], cnt[3]);
			//for(int x = 1; x <= cnt[mx]; x++) printf("b[%d] = %lld\n", x, b[mx][x]);
			sort(b[mx] + 1, b[mx] + 1 + cnt[mx]);
			for(int x = 1; x <= cnt[mx] - n / 2; x++) ans -= b[mx][x];
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
