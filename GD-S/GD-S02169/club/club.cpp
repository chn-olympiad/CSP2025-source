#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int t, n, cnt[4], a[N][4];ll ans;
priority_queue <int> heap[4];

void read(int &x)
{
	x = 0;char c = getchar();
	while(c < 48 || 57 < c)c = getchar();
	while(48 <= c && c <= 57)x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	read(t);
	while(t--)
	{
		ans = 0;
		for(int i = 1;i <= 3;i++)
		{
			while(!heap[i].empty())
				heap[i].pop();
			cnt[i] = 0;
		}

		read(n);
		for(int i = 1;i <= n;i++)
		{
			int mxc = 0, mxv = 0, smc = 0, smv = 0;
			for(int j = 1;j <= 3;j++)
			{
				read(a[i][j]);
				if(mxv <= a[i][j])smc = mxc, smv = mxv, mxc = j, mxv = a[i][j];
				else if(smv <= a[i][j])smc = j, smv = a[i][j];
			}
			if(cnt[mxc] < (n >> 1))ans += mxv, cnt[mxc]++, heap[mxc].push(smv - mxv);
			else
			{
				int x = heap[mxc].top();
				if(smv < x + mxv)ans += x + mxv, heap[mxc].pop(), heap[mxc].push(smv - mxv);
				else ans += smv;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
