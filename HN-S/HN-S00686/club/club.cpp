//另一种写法
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int t , n;
//struct node
//{
//	int a , id;
//}a3[N];
//int cmp(node x , node y)
//{
//	return x.a > y.a;
//}
//int main()
//{
//	//freopen("club.in" , "r" , stdin);
//	//freopen("club.out" , "w" , stdout);
//	cin >> t;
//	while (t--)
//	{
//		node a1[N] , a2[N];
//		int ans = 0;
//		bool vis[N] = {};
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a1[i].a >> a2[i].a >> a3[i].a;
//		}
//		int j[4] = {};
//		int maxs = n / 2;
//		sort (a1 + 1 , a1 + n + 1 , cmp);
//		sort (a2 + 1 , a2 + n + 1 , cmp);
//		sort (a3 + 1 , a3 + n + 1 , cmp);
//		for (int i = 1; i <= 3; i++)
//		{
//			if (i == 1) j[i]++; ans += a1[j[i]].a; vis[a1[j[i]].id] = 1;
//			if (i == 2) j[i]++; ans += a2[j[i]].a; vis[a2[j[i]].id] = 1;
//			if (i == 3) j[i]++; ans += a3[j[i]].a; vis[a3[j[i]].id] = 1;
//			int qqq = n - 1;
//			int kk = 0;
//			while (qqq--)
//			{
//				int maxn = 0 , idx;
//				for (int k = 1; k <= 3; k++)
//				{
//					while (vis[j[k]] == 1) j[k]++;
//					if (k == 1)
//					{
//						if (a1[i].a > maxn && j[k] + 1 <= maxs && vis[k] == 0)
//						{
//							maxn = a1[i].a;
//							idx = a1[i].id;
//						}
//					}
//					if (k == 2)
//					{
//						if (a2[i].a > maxn && j[k] + 1 <= maxs && vis[k] == 0)
//						{
//							maxn = a2[i].a;
//							idx = a2[i].id;
//						}
//					}
//					if (k == 3)
//					{
//						if (a3[i].a > maxn && j[k] + 1 <= maxs && vis[k] == 0)
//						{
//							maxn = a3[i].a;
//							idx = a3[i].id;
//						}
//					}
//				}
//				vis[idx] = 1;
//				kk += maxn;
//			}
//			ans = max(kk , ans);
//		}
//		cout << ans << '\n';
//	}
//	return 0;
// } 优化方式没有写出来，代码应该只有20分 
#include <bits/stdc++.h>
using namespace std;
int T , n;
const int N = 1e5 + 5;
int s[4];
int cnt , maxn , maxs;
int a1[N] , a2[N] , a3[N];
void dfs(int k)
{
	if (k == n + 1)
	{
		maxn = max(cnt , maxn);
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		if (s[i] + 1 <= maxs)
		{
			if (i == 1) cnt += a1[k];
			else if (i == 2) cnt += a2[k];
			else cnt += a3[k]; 
			s[i]++;
			dfs(k + 1);
			if (i == 1) cnt -= a1[k];
			else if (i == 2) cnt -= a2[k];
			else cnt -= a3[k]; 
			s[i]--;
		}
	}
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(a1 , 0 , sizeof(a1));
		memset(a2 , 0 , sizeof(a2));
		memset(a3 , 0 , sizeof(a3));
		for (int i = 1; i <= n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		memset(s , 0 , sizeof(s));
		cnt = 0 , maxn = 0 , maxs = n / 2;
		dfs(1);	
		cout << maxn << '\n';	
	}
}
