#include<bits/stdc++.h>

int fread()
{
	char ch = 'a';
	int ans = 0;
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

void run()
{
	int n;
	long long int ans = 0;
	std::vector<int> units[3];
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
	{
		std::pair<int, int> x[3];
		for(int j = 0; j < 3; ++j)
		{
			x[j].second = j;
			//scanf("%d", &x[j].first);
			x[j].first = fread();
		}	
		
		if(x[2] > x[1]) {std::swap(x[1], x[2]);}
		if(x[1] > x[0]) {std::swap(x[0], x[1]);}
		if(x[2] > x[1]) {std::swap(x[1], x[2]);}
		
		units[x[0].second].push_back({x[0].first - x[1].first});
		ans += x[0].first;
	}
	
	int chan = -1;
	for(int i = 0; i < 3; ++i)
	{
		if(units[i].size() > n / 2)
		{
			chan = i;
			break;
		}
	}
	
	if(chan >= 0)	
	{
		std::sort(units[chan].begin(), units[chan].end());
		for(int i = 0; i < (units[chan].size() - n / 2); ++i)
		{
			ans -= units[chan][i];
		}
	}
	
	printf("%lld\n", ans);
}

signed main()
{
	freopen("club.in", "r",stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		run();
	}
	return 0;
}
