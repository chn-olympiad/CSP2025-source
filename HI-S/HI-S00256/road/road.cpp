#include<bits/stdc++.h>
using std::pair;

inline int fread()
{
	int ans = 0;
	scanf("%d", &ans);
	return ans;
	
	char ch = 'a';
	
	while(ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}

pair<int, pair<int, int> > paths[1000006];
int unis[10009];

int find(int u)
{
	return (u == unis[u]) ? u : (unis[u] = find(unis[u]));
}

void run()
{
	int n, k, m;
	n = fread();
	m = fread();
	k = fread();
	for(int i = 0; i < m; ++i)
	{
		paths[i].second.first = fread();
		paths[i].second.second = fread();
		paths[i].first = fread();
	}
	for(int i = 0; i <= n; ++i)
	{
		unis[i] = i;
	}
	std::sort(paths, paths + m);
	int ans = 0, cnt = 0, i = 0;
	while(cnt <= n - 2 && i < m)
	{
		//std::cout << find(paths[i].second.second) << " " << find(paths[i].second.first) << std::endl;
		if(find(paths[i].second.second) != find(paths[i].second.first))
		{
			unis[find(paths[i].second.second)] = find(paths[i].second.first);
			ans += paths[i].first;
			cnt += 1;
		}
		i += 1;
	}
	//std::cout << ans;
	printf("%d", ans);
}

signed main()
{
	freopen("road.in", "r",stdin);
	freopen("road.out", "w", stdout);
	run();
	return 0;
}
