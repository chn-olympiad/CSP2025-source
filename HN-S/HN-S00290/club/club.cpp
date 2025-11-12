#include <bits/stdc++.h>
using namespace std;

int t , ans , n;
bool vis[200005];
struct node
{
	int a , b , c;
}x[200005];

bool cmp(node x , node y)
{
	return x.a > y.a;
}

void dfs(int sum , int A , int B , int C , int step)
{
	if(step == n)
	{
		ans = max(ans , sum);
		return ;
	}
	for(int i = step;i <= n;i ++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			if(A < n / 2)
			{
				dfs(sum + x[i].a , A + 1 , B , C , step + 1);
			}
			if(B < n / 2)
			{
				dfs(sum + x[i].b , A , B + 1 , C , step + 1);
			}
			if(C < n / 2)
			{
				dfs(sum + x[i].c , A , B , C + 1 , step + 1);
			}
			vis[i] = 0;
		}
	}
	return ;
}

void dfs2(int sum , int A , int B , int step)
{
	if(step == n)
	{
		ans = max(ans , sum);
		return ;
	}
	for(int i = step;i <= n;i ++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			if(A < n / 2)
			{
				dfs2(sum + x[i].a , A + 1 , B , step + 1);
			}
			if(B < n / 2)
			{
				dfs2(sum + x[i].b , A , B + 1 , step + 1);
			}
			vis[i] = 0;
		}
	}
	return ;
}

int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t --)
	{
		bool f = 0 , f2 = 0;
		ans = 0;
		memset(x , 0 , sizeof x);
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i].a >> x[i].b >> x[i].c;
			if(x[i].c != 0)
			{
				f = 1 , f2 = 1;
			}
			if(x[i].b != 0)
			{
				f = 1;
			}
		}
		if(n <= 30)
		{
			dfs(0 , 0 , 0 , 0 , 0);
			cout << ans << "\n";
		}
		else if(f == 0)
		{
			long long sum;
			sort(x + 1 , x + n + 1 , cmp);
			for(int i = 1;i <= n / 2;i ++)
			{
				sum += x[i].a;
			}
			cout << sum << "\n";
		}
		else if(f2 == 0)
		{
			dfs2(0 , 0 , 0 , 0);
			cout << ans << "\n";
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
