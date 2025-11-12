#include <bits/stdc++.h>

using namespace std;
const int maxn = 100004;
int n, T;


long long generatex(int a, int b, int c)
{
	return ((long long)a)*10000000000 +
			((long long)b)*100000 +
			(long long)c;
}
int get_first(long long x)
{
	long long ans = x/(long long)10000000000;
	return (int)ans;
}
int get_second(long long x)
{
	long long ans = x/(long long)100000;
	return (int)ans % 100000;
}
int get_third(long long x)
{
	long long ans = x % 100000;
	return (int)ans % 100000;
}
int get_anys(long long x, int tp)
{
	if(tp == 0) return get_first(x);
	if(tp == 1) return get_second(x);
	else return get_third(x);
	return -1;
}

vector<pair<long long, int>> arr[maxn]; // val, ind 
pair<long long, int> delta_val[maxn]; // deltaval, i
int cnt[maxn];

void solve()
{
	for(int i=0;i<=n;i++)
	{
		cnt[i] = 0;
		delta_val[i] = {0, 0};
		arr[i].clear();
	}
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		arr[i].push_back({a, 0});
		arr[i].push_back({b, 1});
		arr[i].push_back({c, 2});
		sort(arr[i].begin(), arr[i].end());
		// arr size must be : 3
	}
	// next step: choose the max.
	long long best_sol = 0;
	for(int i=1;i<=n;i++)
	{
		best_sol += arr[i][2].first;
		cnt[arr[i][2].second]++;
	}
	int bad_colu = -1;
	if(cnt[0] > n/2) bad_colu = 0;
	if(cnt[1] > n/2) bad_colu = 1;
	if(cnt[2] > n/2) bad_colu = 2;
	if(bad_colu == -1)
	{
		printf("%lld\n", best_sol);
		return; 
	}
	// find the min of delta!
	for(int i=1;i<=n;i++)
	{
		delta_val[i] = {arr[i][2].first - arr[i][1].first, i}; // val , line
	}
	sort(delta_val+1, delta_val+n+1);
	for(int i=1;i<=n;i++)
	{
		// if delta_val i cnt is originally not bad, do not modify
		int cur_line = delta_val[i].second;
		if(arr[cur_line][2].second != bad_colu) continue;
		// otherwise, bad_colu cnt--, and others++
		cnt[bad_colu]--;
		best_sol -= delta_val[i].first;
		cnt[arr[cur_line][1].second] ++;
		if(cnt[arr[cur_line][1].second] > n/2) printf("noway!"); // i expect this will not happen.
		if(cnt[arr[cur_line][2].second] <= n/2) break;
	}
	printf("%lld\n", best_sol);
	// wc last 13min AC all examples!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// i am colGem ! yeah yeah yeah yeyeyeyeyeyeyey
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}

