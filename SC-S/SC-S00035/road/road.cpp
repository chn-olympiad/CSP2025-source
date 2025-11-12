#include<bits/stdc++.h>

#define int long long

using namespace std;

int n = 0 , m = 0 , k = 0 , cnt = 0 , ans = 0 , it = 0;

struct Lilies{
	int x;
	int y;
	int val;
};

array<int , 100100> fa;

int find(int x)
{
	while(x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

array<Lilies , 1000100> line;

array<Lilies , 200100> tmp , backup;

array<int , 100100> extra;

array<array<int , 100100> , 11> cost;

signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;
	
	for(int i = 1;i <= n;++ i) fa[i] = i;
	
	for(int i = 1;i <= m;++ i) cin >> line[i].x >> line[i].y >> line[i].val;
	
	it = m;
	
	for(int i = 1;i <= k;++ i)
	{
		cin >> extra[i];
		
		for(int j = 1;j <= n;++ j) cin >> cost[i][j];
	}
	
	sort(line.data() + 1 , line.data() + m + 1 , [&](Lilies x , Lilies y){return x.val < y.val;});
	
	for(int i = 1;i <= m;++ i)
	{
		int rx = find(line[i].x) , ry = find(line[i].y);
		
		if(rx != ry)
		{
			fa[rx] = ry;
			tmp[++ cnt] = line[i];
			ans += line[i].val;
			if(cnt == n - 1) break;
		}
	}
	
	backup = tmp;
	
	int ANS = ans;
	
	for(int state = 1;state < (1 << k);++ state)
	{
		int res = 0 , N = n , now = 0;
		
		it = cnt;
		
		tmp = backup;
		
		for(int x = 1;x <= k;++ x)
		{
			if(state & (1 << (x - 1)))
			{
				++ N;
				
				res += extra[x];
				
				for(int i = 1;i <= n;++ i) tmp[++ it] = {x + n , i , cost[x][i]};
			}
		}
		
		if(res > ANS) continue;
		
		sort(tmp.data() + 1 , tmp.data() + it + 1 , [&](Lilies a , Lilies b){return a.val < b.val;});
		
		for(int i = 1;i <= n;++ i) fa[i] = i;
		
		for(int x = 1;x <= k;++ x) if(state & (1 << (x - 1))) fa[x + n] = x + n;
		
		for(int i = 1;i <= it;++ i)
		{
			int rx = find(tmp[i].x) , ry = find(tmp[i].y);
			
			if(rx != ry)
			{
				fa[rx] = ry;
				
				res += tmp[i].val;
				
				++ now;
				
				if(now == N - 1) break;
			}
		}
		
		ANS = min(ANS , res);
	}
	
	cout << ANS << endl;
	return 0;
}