#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	// int f = 1?
	int res = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int MAXN = 1e5 + 10;

int t, n, a[MAXN][3], b[MAXN], ans, cnt[3];

priority_queue<int> qu;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	t = read();
	while (t--)
	{
		n = read();
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++) a[i][j] = read();
		
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 1; i <= n; i++)
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) ans += a[i][0], b[i] = 0, cnt[0]++;
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) ans += a[i][1], b[i] = 1, cnt[1]++;
			else ans += a[i][2], b[i] = 2, cnt[2]++;
		
		while (qu.size()) qu.pop();
		int flag = 114514;
		if (cnt[0] > n / 2)
		{
			flag = 0;
			for (int i = 1; i <= n; i++)
				if (b[i] == 0) qu.push(max(a[i][1], a[i][2]) - a[i][0]);
		}
		else if (cnt[1] > n / 2)
		{
			flag = 1;
			for (int i = 1; i <= n; i++)
				if (b[i] == 1) qu.push(max(a[i][0], a[i][2]) - a[i][1]);
		}
		else if (cnt[2] > n / 2)
		{
			flag = 2;
			for (int i = 1; i <= n; i++)
				if (b[i] == 2) qu.push(max(a[i][0], a[i][1]) - a[i][2]);
		}
		if (flag != 114514)
			while (cnt[flag] > n / 2) ans += qu.top(), qu.pop(), cnt[flag]--;
		printf("%d\n", ans);
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
