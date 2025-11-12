#include <bits/stdc++.h>
using namespace std;

int n,cnt[5],zj[100005],ans,bh[35];
struct node
{
	int a,b,c,id;
}a[100005];
bool f[100005];
bool cmp(node a,node b)
{
	return max(a.a,max(a.b,a.c)) > max(b.a,max(b.b,b.c));
}
void dfs(int x)
{
	int sum = 0;
	if(cnt[1] > n / 2) return;
	if(cnt[2] > n / 2) return;
	if(cnt[3] > n / 2) return;
	if(x > n)
	{
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(bh[i] == 1) sum += a[i].a;
			if(bh[i] == 2) sum += a[i].b;
			if(bh[i] == 3) sum += a[i].c;
		}
		ans = max(ans,sum);
		return;
	}
	cnt[1]++;
	bh[x] = 1;
	dfs(x + 1);
	cnt[1]--;
	cnt[2]++;
	bh[x] = 2;
	dfs(x + 1);
	cnt[2]--;
	cnt[3]++;
	bh[x] = 3;
	dfs(x + 1);
	bh[x] = 0;
	cnt[3]--;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t > 0)
	{
		t--;
		ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		cin >> n;
		bool fla = true;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].id = i;
			if(a[i].b != 0) fla = false;
		}
		if(n <= 30)
		{
			dfs(1);
			cout << ans << endl;
			continue;
		}
		if(fla)
		{
			int ans = 0;
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++)
			{
				ans += a[i].a;
			}
			cout << ans << endl;
			continue;
		}
		sort(a + 1,a + n + 1,cmp);
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(f[a[i].id]) continue;
			f[a[i].id] = true;
			if(a[i].a >= a[i].b&&a[i].a >= a[i].c)
			{
				if(cnt[1] >= n / 2)
				{
					int maxn = -1e9,b = 0,l = 0;
					for(int j = 1;j < i;j++)
					{
						if(zj[j] == 1)
						{
							if(a[j].b - a[j].a + a[i].a > maxn)
							{
								maxn = max(maxn,a[j].b - a[j].a + a[i].a);
								b = j;
								l = 2;
							}
							if(a[j].c - a[j].a + a[i].a > maxn)
							{
								maxn = max(maxn,a[j].c - a[j].a + a[i].a);
								b = j;
								l = 3;
							}
						}
					}
					if(maxn > 0)
					{
						zj[b] = l;
						cnt[l]++;
						sum += maxn;
						zj[i] = 1;
					}
					else
					{
						if(a[i].b > a[i].c)
						{
							maxn = a[i].b;
							l = 2;
						}
						else
						{
							maxn = a[i].c;
							l = 3;
						}
						zj[i] = l;
						sum += maxn;
						cnt[l]++;
					}
				}
				else
				{
					cnt[1]++;
					zj[i] = 1;
					sum += a[i].a;
				}
			}
			else if(a[i].b >= a[i].a&&a[i].b >= a[i].c)
			{
				if(cnt[2] >= n / 2)
				{
					int maxn = -1e9,b = 0,l = 0;
					for(int j = 1;j < i;j++)
					{
						if(zj[j] == 2)
						{
							if(a[j].a - a[j].b + a[i].b > maxn)
							{
								maxn = max(maxn,a[j].a - a[j].b + a[i].b);
								b = j;
								l = 1;
							}
							if(a[j].c - a[j].b + a[i].b > maxn)
							{
								maxn = max(maxn,a[j].c - a[j].b + a[i].b);
								b = j;
								l = 3;
							}
						}
					}
					if(maxn > 0)
					{
						zj[b] = l;
						cnt[l]++;
						sum += maxn;
						zj[i] = 2;
					}
					else
					{
						if(a[i].a > a[i].c)
						{
							maxn = a[i].a;
							l = 1;
						}
						else
						{
							maxn = a[i].c;
							l = 3;
						}
						zj[i] = l;
						sum += maxn;
						cnt[l]++;
					}
				}
				else
				{
					cnt[2]++;
					zj[i] = 2;
					sum += a[i].b;
				}
			}
			else
			{
				if(cnt[3] >= n / 2)
				{
					int maxn = -1e9,b = 0,l = 0;
					for(int j = 1;j < i;j++)
					{
						if(zj[j] == 3)
						{
							if(a[j].a - a[j].c + a[i].c > maxn)
							{
								maxn = max(maxn,a[j].a - a[j].c + a[i].c);
								b = j;
								l = 1;
							}
							if(a[j].b - a[j].c + a[i].c > maxn)
							{
								maxn = max(maxn,a[j].b - a[j].c + a[i].c);
								b = j;
								l = 2;
							}
						}
					}
					if(maxn > 0)
					{
						zj[b] = l;
						cnt[l]++;
						sum += maxn;
						zj[i] = 3;
					}
					else
					{
						if(a[i].a > a[i].b)
						{
							maxn = a[i].a;
							l = 1;
						}
						else
						{
							maxn = a[i].b;
							l = 2;
						}
						zj[i] = l;
						sum += maxn;
						cnt[l]++;
					}
				}
				else
				{
					cnt[3]++;
					zj[i] = 3;
					sum += a[i].c;
				}
			}
		//	cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << a[i].id << ' ' << sum << endl;
		}
		cout << sum << endl;
		memset(f,0,sizeof(f));
	}
	return 0;
}
