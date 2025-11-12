#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
typedef pair<LL, int> PLI;
int n, cnt[5];
bool st[N];
LL sum;
struct node
{
	LL val[5];
	int id;
}w[N];
void T(int id)
{
	priority_queue<PLI> q;
	for (int i = 1; i <= n; i ++)
	{
		if (w[i].id != id)continue;
		for (int j = 1; j <= 3; j ++)
		{
			if (j == id)continue;
			q.push({w[i].val[j] - w[i].val[id], i});
		}
	}
	while (q.size() && cnt[id] > n / 2)
	{
		PLI u = q.top();
		q.pop();
		if (st[u.second])continue;
		sum += u.first;
		st[u.second] = 1;
		cnt[id] --;
	}
}
void work()
{
	cnt[1] = cnt[2] = cnt[3] = sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		st[i] = 0;
		LL Max = 0;
		int id = 0;
		for (int j = 1; j <= 3; j ++)
		{
			scanf("%lld", &w[i].val[j]);
			if (Max < w[i].val[j])
			{
				Max = w[i].val[j];
				id = j;
			}
		}
		sum += Max;
		cnt[w[i].id = id] ++;
	}
	for (int i = 1; i <= 3; i ++)
	{
		if (cnt[i] > (n / 2))T(i);
	}
	printf("%lld\n", sum);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T --)work();
	return 0;
}