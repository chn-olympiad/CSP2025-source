#include<iostream>
#include<algorithm>
using namespace std;

int T, n, cnt[5];
long long ans = 0;
struct node{
	int x, y, z;
	int maxn, maxty, sty, minty, ty;
}a[100010];
struct str{
	int id, x;
}cntx[5];
bool cmp(node x, node y)
{
	return x.maxn > y.maxn;
}
bool cmp1(str x, str y)
{
	return x.x < y.x;
}
void dfs(int now, long long sum)
{
	if(now > n)
	{
		ans = max(ans, sum);
		return ;
	}
	if(cnt[1] < (n / 2))
	{
		cnt[1]++;
		dfs(now + 1, sum + a[now].x);
		cnt[1]--;
	}
	if(cnt[2] < (n / 2))
	{
		cnt[2]++;
		dfs(now + 1, sum + a[now].y);
		cnt[2]--;	
	}
	if(cnt[3] < (n / 2))
	{
		cnt[3]++;
		dfs(now + 1, sum + a[now].z);
		cnt[3]--;	
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		ans = 0;
		bool flg = false;
		cnt[1] = cnt[2] = cnt[3] = 0;
		cntx[1].id = 1;
		cntx[2].id = 2;
		cntx[3].id = 3;
		cntx[1].x = cntx[2].x = cntx[3].x = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxn = max(a[i].x, max(a[i].y, a[i].z));
			if(a[i].y != a[i].z) flg = true;
		}
		if(!flg)
		{
			int cnt = 0;
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n; i++)
			{
				ans += a[i].maxn;
				cnt++;
				if(cnt > n / 2) break;
			}
			cout << ans << endl;
			continue;
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
