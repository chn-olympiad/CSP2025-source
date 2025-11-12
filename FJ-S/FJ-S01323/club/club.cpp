#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 1e5+5;
int n, a[N], b[N], c[N], cnt[5], res;
int t[N], tt; 

int cmp(int i)
{
	if(max(a[i], max(b[i], c[i])) == a[i]) return 1;
	if(max(a[i], max(b[i], c[i])) == b[i]) return 2;
	if(max(a[i], max(b[i], c[i])) == c[i]) return 3;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		tt = res = cnt[1] = cnt[2] = cnt[3] = 0;
		memset(t, 0, sizeof t);
		
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d%d", a + i, b + i, c + i);
		rep(i, 1, n) res += max(a[i], max(b[i], c[i])), cnt[cmp(i)]++;
		if(cnt[1] > (n >> 1))     {rep(i, 1, n) if(cmp(i) == 1) t[++tt] = min(a[i] - b[i], a[i] - c[i]); }
		else if(cnt[2] > (n >> 1)){rep(i, 1, n) if(cmp(i) == 2) t[++tt] = min(b[i] - a[i], b[i] - c[i]); }
		else if(cnt[3] > (n >> 1)){rep(i, 1, n) if(cmp(i) == 3) t[++tt] = min(c[i] - a[i], c[i] - b[i]); }
		else
		{
			printf("%d\n", res);
			continue;
		}
		sort(t + 1, t + tt + 1);
		int num = max(cnt[1], max(cnt[2], cnt[3])) - (n >> 1);
		rep(i, 1, num)
		{
			res -= t[i];
		}
		printf("%d\n", res);
	}
	return 0;
}

