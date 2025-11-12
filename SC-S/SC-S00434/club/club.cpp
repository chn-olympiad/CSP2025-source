#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
priority_queue<pair<pair<int ,int>, int> > q[10];
int a, b, c;
int num[5], maxx, k;
long long ans;
bool flag[10][N];

void work(int x, int nnum)
{
	while(num[x] > k)
	{
		int w = q[nnum].top().first.first, idx = q[nnum].top().first.second, ii = q[nnum].top().second;
		q[nnum].pop();
		if(ii != x || flag[nnum][idx]) continue;			
		flag[nnum][idx] = 1;
		ans += w;
		num[x]--;
//		printf("w:%d, idx:%d, ii:%d\n", w, idx, ii);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		int n;
		k = a = b = c = 0;
		scanf("%d", &n);
		memset(num, 0, sizeof num);
		maxx = -1;
		ans = 0;
		k = n / 2;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			maxx = max(a, max(b, c));
			if(maxx == a)
			{
				num[1]++;
				q[T].push({{max(c - maxx, b - maxx), i}, 1});
//				cout << 1 << endl;
			}
			else if(maxx == b)
			{
				num[2]++;
				q[T].push({{max(c - maxx, a - maxx), i}, 2});
//				cout << 2 << endl;
			}
			else if(maxx == c)
			{
				num[3]++;
				q[T].push({{max(a - maxx, b - maxx), i}, 3});
//				cout << 3 << endl;
			}
			ans += maxx;
		}
		if(num[1] > k) work(1, T);
		else if(num[2] > k) work(2, T);
		else if(num[3] > k) work(3, T);
		printf("%lld\n", ans);
	}
	return 0;
}
/*
bro们谁懂T1写了2h的绝望感 RP++
*/