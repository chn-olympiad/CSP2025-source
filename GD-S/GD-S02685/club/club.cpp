//////#include <iostream>
//////#include <algorithm>
//////#include <cstring> 
//////using namespace std;
//////
//////const int N = 1e5 + 5;
//////
////////struct Human
////////{
////////	int x, y, z, 
////////		nx, ny, nz, 
////////		nxid, nyid, nzid;
////////} a[N];
//////
////////struct Human
////////{
////////	int v, id;
////////} a[N][5];
//////
//////struct Node
//////{
//////	int v, id;
//////};
//////
//////struct Human
//////{
//////	Node r[5];
////////	int nx, ny, nz, 
////////		nxid, nyid, nzid;
//////} a[N];
//////
//////int t, n, maxv, cnt[5], ans;
//////
//////int main()
//////{
////////	freopen("club.in", "r", stdin);
////////	freopen("club.out", "w", stdout);
//////	
//////	scanf("%d", &t);
//////	
//////	while (t --)
//////	{
//////		cnt[1] = cnt[2] = cnt[3] = 0;
//////		ans = 0;
//////
//////		scanf("%d", &n);
//////		maxv = n >> 1;
//////
//////		for (int i = 1; i <= n; ++ i)
//////		{
//////			cin >> a[i].r[1].v >> a[i].r[2].v >> a[i].r[3].v;
//////
//////			a[i].r[1].id = 1;
//////			a[i].r[2].id = 2;
//////			a[i].r[3].id = 3;
//////
//////			sort(a[i].r + 1, a[i].r + 4, [&](const Node &x, const Node &y)
//////			{
//////				if (x.v != y.v)
//////				{
//////					return x.v > y.v;
//////				}
//////				return x.id < y.id;
//////			});
//////		}
//////		
//////		sort(a + 1, a + n + 1, [&](const Human &x, const Human &y)
//////		{
//////			if (x.r[1].v != y.r[1].v)
//////			{
//////				return x.r[1].v > y.r[1].v;
//////			}
//////			else if (x.r[2].v != y.r[2].v)
//////			{
//////				return x.r[2].v > y.r[2].v;
//////			}
//////			return x.r[3].v > y.r[3].v;
//////		});
//////		
//////		for (int i = 1; i <= n; ++ i)
//////		{
//////			if (cnt[a[i].r[1].id] < maxv)
//////			{
//////				ans += a[i].r[1].v;
//////				++ cnt[a[i].r[1].id];
//////			}
//////			else if (cnt[a[i].r[2].id] < maxv)
//////			{
//////				ans += a[i].r[2].v;
//////				++ cnt[a[i].r[2].id];
//////			}
//////			else
//////			{
//////				ans += a[i].r[3].v;
//////				++ cnt[a[i].r[3].id];
//////			}
//////		}
//////		
//////		printf("%d\n", ans);
//////	}
//////}
////
////#include <iostream>
////#include <algorithm>
////#include <cstring> 
////using namespace std;
////
////const int N = 1e5 + 5;
////
////struct Node
////{
////	int v, id;
////};
////
////struct Human
////{
////	Node r[5];
////} a[N];
////
////struct DP
////{
////	int v, cnt[5];
////} dp[N][5];
////
////int t, n, maxv;
////
////int main()
////{
//////	freopen("club.in", "r", stdin);
//////	freopen("club.out", "w", stdout);
////	
////	scanf("%d", &t);
////	
////	while (t --)
////	{
////		scanf("%d", &n);
////		maxv = n >> 1;
////
////		for (int i = 1; i <= n; ++ i)
////		{
////			cin >> a[i].r[1].v >> a[i].r[2].v >> a[i].r[3].v;
////
////			a[i].r[1].id = 1;
////			a[i].r[2].id = 2;
////			a[i].r[3].id = 3;
////
////			sort(a[i].r + 1, a[i].r + 4, [&](const Node &x, const Node &y)
////			{
////				if (x.v != y.v)
////				{
////					return x.v > y.v;
////				}
////				return x.id < y.id;
////			});
////			
////			dp[i][1].v = dp[i][1].cnt[1] = dp[i][1].cnt[2] = dp[i][1].cnt[3] = 
////			dp[i][2].v = dp[i][2].cnt[1] = dp[i][2].cnt[2] = dp[i][1].cnt[3] = 
////			dp[i][3].v = dp[i][3].cnt[1] = dp[i][3].cnt[2] = dp[i][3].cnt[3] = 0;
////		}
////		
////		sort(a + 1, a + n + 1, [&](const Human &x, const Human &y)
////		{
////			if (x.r[1].v != y.r[1].v)
////			{
////				return x.r[1].v > y.r[1].v;
////			}
////			else if (x.r[2].v != y.r[2].v)
////			{
////				return x.r[2].v > y.r[2].v;
////			}
////			return x.r[3].v > y.r[3].v;
////		});
////
//////		for (int i = 1; i <= n; ++ i)
//////		{
//////			printf("[%d] %d(%d) %d(%d) %d(%d)\n", i, 
//////			a[i].r[1].v, a[i].r[1].id, 
//////			a[i].r[2].v, a[i].r[2].id, 
//////			a[i].r[3].v, a[i].r[3].id);
//////		}
////		
////		for (int i = 1; i <= n; ++ i)
////		{
//////			printf("DP on [%d]\n", i);
//////			printf("  Dp 1 %d, %d\n", a[i].r[1].v, a[i].r[1].id);
////			if (dp[i - 1][1].cnt[a[i].r[1].id] < maxv)
////			{
////				dp[i][1].v = dp[i - 1][1].v + a[i].r[1].v;
//////				++ dp[i][1].cnt[a[i].r[1].id];
////				dp[i][1].cnt[1] = dp[i - 1][1].cnt[1];
////				dp[i][1].cnt[2] = dp[i - 1][1].cnt[2];
////				dp[i][1].cnt[3] = dp[i - 1][1].cnt[3];
////				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][1].cnt[a[i].r[1].id] + 1;
////
//////				printf("    Dp 1 Successfully On 1 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][1].cnt[a[i].r[1].id], 
//////				dp[i - 1][1].v, a[i].r[1].v, 
//////				dp[i][1].cnt[a[i].r[1].id]);
////			}
////			if (dp[i - 1][2].cnt[a[i].r[1].id] < maxv && dp[i - 1][2].v + a[i].r[1].v > dp[i][1].v)
////			{
////				dp[i][1].v = dp[i - 1][2].v + a[i].r[1].v;
//////				++ dp[i][1].cnt[a[i].r[1].id];
////				dp[i][1].cnt[1] = dp[i - 1][2].cnt[1];
////				dp[i][1].cnt[2] = dp[i - 1][2].cnt[2];
////				dp[i][1].cnt[3] = dp[i - 1][2].cnt[3];
////				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][2].cnt[a[i].r[1].id] + 1;
////
//////				printf("    Dp 1 Successfully On 2 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][2].cnt[a[i].r[1].id], 
//////				dp[i - 1][2].v, a[i].r[1].v, 
//////				dp[i][1].cnt[a[i].r[1].id]);
////			}
////			if (dp[i - 1][3].cnt[a[i].r[1].id] < maxv && dp[i - 1][3].v + a[i].r[1].v > dp[i][1].v)
////			{
////				dp[i][1].v = dp[i - 1][3].v + a[i].r[1].v;
//////				++ dp[i][1].cnt[a[i].r[1].id];
////				dp[i][1].cnt[1] = dp[i - 1][3].cnt[1];
////				dp[i][1].cnt[2] = dp[i - 1][3].cnt[2];
////				dp[i][1].cnt[3] = dp[i - 1][3].cnt[3];
////				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][3].cnt[a[i].r[1].id] + 1;
////
//////				printf("    Dp 1 Successfully On 3 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][3].cnt[a[i].r[1].id], 
//////				dp[i - 1][3].v, a[i].r[1].v, 
//////				dp[i][1].cnt[a[i].r[1].id]);
////			}
////			
//////			printf("  Dp 2 %d, %d\n", a[i].r[2].v, a[i].r[2].id);
////			if (dp[i - 1][1].cnt[a[i].r[2].id] < maxv)
////			{
////				dp[i][2].v = dp[i - 1][1].v + a[i].r[2].v;
//////				++ dp[i][2].cnt[a[i].r[2].id];
////				dp[i][2].cnt[1] = dp[i - 1][1].cnt[1];
////				dp[i][2].cnt[2] = dp[i - 1][1].cnt[2];
////				dp[i][2].cnt[3] = dp[i - 1][1].cnt[3];
////				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][1].cnt[a[i].r[2].id] + 1;
////
//////				printf("    Dp 2 Successfully On 1 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][1].cnt[a[i].r[2].id], 
//////				dp[i - 1][1].v, a[i].r[2].v, 
//////				dp[i][2].cnt[a[i].r[2].id]);
////			}
////			if (dp[i - 1][2].cnt[a[i].r[2].id] < maxv && dp[i - 1][2].v + a[i].r[2].v > dp[i][2].v)
////			{
////				dp[i][2].v = dp[i - 1][2].v + a[i].r[2].v;
//////				++ dp[i][2].cnt[a[i].r[2].id];
////				dp[i][2].cnt[1] = dp[i - 1][2].cnt[1];
////				dp[i][2].cnt[2] = dp[i - 1][2].cnt[2];
////				dp[i][2].cnt[3] = dp[i - 1][2].cnt[3];
////				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][2].cnt[a[i].r[2].id] + 1;
////
//////				printf("    Dp 2 Successfully On 2 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][2].cnt[a[i].r[2].id], 
//////				dp[i - 1][2].v, a[i].r[2].v, 
//////				dp[i][2].cnt[a[i].r[2].id]);
////			}
////			if (dp[i - 1][3].cnt[a[i].r[2].id] < maxv && dp[i - 1][3].v + a[i].r[2].v > dp[i][2].v)
////			{
////				dp[i][2].v = dp[i - 1][3].v + a[i].r[2].v;
//////				++ dp[i][2].cnt[a[i].r[2].id];
////				dp[i][2].cnt[1] = dp[i - 1][3].cnt[1];
////				dp[i][2].cnt[2] = dp[i - 1][3].cnt[2];
////				dp[i][2].cnt[3] = dp[i - 1][3].cnt[3];
////				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][3].cnt[a[i].r[2].id] + 1;
////
//////				printf("    Dp 2 Successfully On 3 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][3].cnt[a[i].r[2].id], 
//////				dp[i - 1][3].v, a[i].r[2].v, 
//////				dp[i][2].cnt[a[i].r[2].id]);
////			}
////			
//////			printf("  Dp 3 %d, %d\n", a[i].r[3].v, a[i].r[3].id);
////			if (dp[i - 1][1].cnt[a[i].r[3].id] < maxv)
////			{
////				dp[i][3].v = dp[i - 1][1].v + a[i].r[3].v;
//////				++ dp[i][3].cnt[a[i].r[3].id];
////				dp[i][3].cnt[1] = dp[i - 1][1].cnt[1];
////				dp[i][3].cnt[2] = dp[i - 1][1].cnt[2];
////				dp[i][3].cnt[3] = dp[i - 1][1].cnt[3];
////				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][1].cnt[a[i].r[3].id] + 1;
////
//////				printf("    Dp 3 Successfully On 1 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][1].cnt[a[i].r[3].id], 
//////				dp[i - 1][1].v, a[i].r[3].v, 
//////				dp[i][3].cnt[a[i].r[3].id]);
////			}
////			if (dp[i - 1][2].cnt[a[i].r[3].id] < maxv && dp[i - 1][2].v + a[i].r[3].v > dp[i][3].v)
////			{
////				dp[i][3].v = dp[i - 1][2].v + a[i].r[3].v;
//////				++ dp[i][3].cnt[a[i].r[3].id];
////				dp[i][3].cnt[1] = dp[i - 1][2].cnt[1];
////				dp[i][3].cnt[2] = dp[i - 1][2].cnt[2];
////				dp[i][3].cnt[3] = dp[i - 1][2].cnt[3];
////				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][2].cnt[a[i].r[3].id] + 1;
////
//////				printf("    Dp 3 Successfully On 2 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][2].cnt[a[i].r[3].id], 
//////				dp[i - 1][2].v, a[i].r[3].v, 
//////				dp[i][3].cnt[a[i].r[3].id]);
////			}
////			if (dp[i - 1][3].cnt[a[i].r[3].id] < maxv && dp[i - 1][3].v + a[i].r[3].v > dp[i][3].v)
////			{
////				dp[i][3].v = dp[i - 1][3].v + a[i].r[3].v;
//////				++ dp[i][3].cnt[a[i].r[3].id];
////				dp[i][3].cnt[1] = dp[i - 1][3].cnt[1];
////				dp[i][3].cnt[2] = dp[i - 1][3].cnt[2];
////				dp[i][3].cnt[3] = dp[i - 1][3].cnt[3];
////				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][3].cnt[a[i].r[3].id] + 1;
////
//////				printf("    Dp 3 Successfully On 3 With cnt = %d. v = %d + %d cnt = %d\n", 
//////				dp[i - 1][3].cnt[a[i].r[3].id], 
//////				dp[i - 1][3].v, a[i].r[3].v, 
//////				dp[i][3].cnt[a[i].r[3].id]);
////			}
////		}
////		
////		printf("%d\n", max({dp[n][1].v, dp[n][2].v, dp[n][3].v}));
//////		printf("%d %d %d\n", dp[n][1].v, dp[n][2].v, dp[n][3].v);
////	}
////}
//
//#include <iostream>
//#include <algorithm>
//#include <cstring> 
//using namespace std;
//
//const int N = 1e5 + 5;
//
//struct Node
//{
//	int v, id;
//};
//
//struct Human
//{
//	Node r[5];
//} a[N];
//
//struct DP
//{
//	int v, cnt[5];
//} dp[N][5];
//
//int t, n, maxv;
//
//int main()
//{
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
//
//	scanf("%d", &t);
//	
//	while (t --)
//	{
//		scanf("%d", &n);
//		maxv = n >> 1;
//
//		for (int i = 1; i <= n; ++ i)
//		{
//			cin >> a[i].r[1].v >> a[i].r[2].v >> a[i].r[3].v;
//
//			a[i].r[1].id = 1;
//			a[i].r[2].id = 2;
//			a[i].r[3].id = 3;
//
//			sort(a[i].r + 1, a[i].r + 4, [&](const Node &x, const Node &y)
//			{
//				if (x.v != y.v)
//				{
//					return x.v > y.v;
//				}
//				return x.id < y.id;
//			});
//			
//			dp[i][1].v = dp[i][1].cnt[1] = dp[i][1].cnt[2] = dp[i][1].cnt[3] = 
//			dp[i][2].v = dp[i][2].cnt[1] = dp[i][2].cnt[2] = dp[i][1].cnt[3] = 
//			dp[i][3].v = dp[i][3].cnt[1] = dp[i][3].cnt[2] = dp[i][3].cnt[3] = 0;
//		}
//		
//		sort(a + 1, a + n + 1, [&](const Human &x, const Human &y)
//		{
//			if (x.r[1].v != y.r[1].v)
//			{
//				return x.r[1].v > y.r[1].v;
//			}
//			else if (x.r[2].v != y.r[2].v)
//			{
//				return x.r[2].v > y.r[2].v;
//			}
//			return x.r[3].v > y.r[3].v;
//		});
//
////		for (int i = 1; i <= n; ++ i)
////		{
////			printf("[%d] %d(%d) %d(%d) %d(%d)\n", i, 
////			a[i].r[1].v, a[i].r[1].id, 
////			a[i].r[2].v, a[i].r[2].id, 
////			a[i].r[3].v, a[i].r[3].id);
////		}
//		
//		for (int i = 1; i <= n; ++ i)
//		{
//			if (dp[i - 1][1].cnt[a[i].r[1].id] < maxv)
//			{
//				dp[i][1].v = dp[i - 1][1].v + a[i].r[1].v;
//				dp[i][1].cnt[1] = dp[i - 1][1].cnt[1];
//				dp[i][1].cnt[2] = dp[i - 1][1].cnt[2];
//				dp[i][1].cnt[3] = dp[i - 1][1].cnt[3];
//				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][1].cnt[a[i].r[1].id] + 1;
//			}
//			if (dp[i - 1][2].cnt[a[i].r[1].id] < maxv && (dp[i - 1][2].v + a[i].r[1].v > dp[i][1].v 
//                || (dp[i - 1][2].v + a[i].r[1].v == dp[i][1].v && 
//                (dp[i - 1][2].cnt[a[i].r[1].id] + 1 < dp[i][1].cnt[a[i].r[1].id] ||
//                 (dp[i - 1][2].cnt[1] < dp[i][1].cnt[1] && a[i].r[1].id != 1) || 
//                 (dp[i - 1][2].cnt[2] < dp[i][1].cnt[2] && a[i].r[1].id != 2) || 
//                 (dp[i - 1][2].cnt[3] < dp[i][1].cnt[3] && a[i].r[1].id != 3)))))
//			{
//				dp[i][1].v = dp[i - 1][2].v + a[i].r[1].v;
//				dp[i][1].cnt[1] = dp[i - 1][2].cnt[1];
//				dp[i][1].cnt[2] = dp[i - 1][2].cnt[2];
//				dp[i][1].cnt[3] = dp[i - 1][2].cnt[3];
//				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][2].cnt[a[i].r[1].id] + 1;
//			}
//			if (dp[i - 1][3].cnt[a[i].r[1].id] < maxv && (dp[i - 1][3].v + a[i].r[1].v > dp[i][1].v 
//                || (dp[i - 1][3].v + a[i].r[1].v == dp[i][1].v && 
//                (dp[i - 1][3].cnt[a[i].r[1].id] + 1 < dp[i][1].cnt[a[i].r[1].id] ||
//                 (dp[i - 1][3].cnt[1] < dp[i][1].cnt[1] && a[i].r[1].id != 1) || 
//                 (dp[i - 1][3].cnt[2] < dp[i][1].cnt[2] && a[i].r[1].id != 2) || 
//                 (dp[i - 1][3].cnt[3] < dp[i][1].cnt[3] && a[i].r[1].id != 3)))))
//			{
//				dp[i][1].v = dp[i - 1][3].v + a[i].r[1].v;
//				dp[i][1].cnt[1] = dp[i - 1][3].cnt[1];
//				dp[i][1].cnt[2] = dp[i - 1][3].cnt[2];
//				dp[i][1].cnt[3] = dp[i - 1][3].cnt[3];
//				dp[i][1].cnt[a[i].r[1].id] = dp[i - 1][3].cnt[a[i].r[1].id] + 1;
//			}
//			
//			if (dp[i - 1][1].cnt[a[i].r[2].id] < maxv)
//			{
//				dp[i][2].v = dp[i - 1][1].v + a[i].r[2].v;
//				dp[i][2].cnt[1] = dp[i - 1][1].cnt[1];
//				dp[i][2].cnt[2] = dp[i - 1][1].cnt[2];
//				dp[i][2].cnt[3] = dp[i - 1][1].cnt[3];
//				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][1].cnt[a[i].r[2].id] + 1;
//			}
//			if (dp[i - 1][2].cnt[a[i].r[2].id] < maxv && (dp[i - 1][2].v + a[i].r[2].v > dp[i][2].v 
//                || (dp[i - 1][2].v + a[i].r[2].v == dp[i][2].v && 
//                (dp[i - 1][2].cnt[a[i].r[2].id] + 1 < dp[i][2].cnt[a[i].r[2].id] ||
//                 (dp[i - 1][2].cnt[1] < dp[i][2].cnt[1] && a[i].r[2].id != 1) || 
//                 (dp[i - 1][2].cnt[2] < dp[i][2].cnt[2] && a[i].r[2].id != 2) || 
//                 (dp[i - 1][2].cnt[3] < dp[i][2].cnt[3] && a[i].r[2].id != 3)))))
//			{
//				dp[i][2].v = dp[i - 1][2].v + a[i].r[2].v;
//				dp[i][2].cnt[1] = dp[i - 1][2].cnt[1];
//				dp[i][2].cnt[2] = dp[i - 1][2].cnt[2];
//				dp[i][2].cnt[3] = dp[i - 1][2].cnt[3];
//				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][2].cnt[a[i].r[2].id] + 1;
//			}
//			if (dp[i - 1][3].cnt[a[i].r[2].id] < maxv && (dp[i - 1][3].v + a[i].r[2].v > dp[i][2].v 
//                || (dp[i - 1][3].v + a[i].r[2].v == dp[i][2].v && 
//                (dp[i - 1][3].cnt[a[i].r[2].id] + 1 < dp[i][2].cnt[a[i].r[2].id] ||
//                 (dp[i - 1][3].cnt[1] < dp[i][2].cnt[1] && a[i].r[2].id != 1) || 
//                 (dp[i - 1][3].cnt[2] < dp[i][2].cnt[2] && a[i].r[2].id != 2) || 
//                 (dp[i - 1][3].cnt[3] < dp[i][2].cnt[3] && a[i].r[2].id != 3)))))
//			{
//				dp[i][2].v = dp[i - 1][3].v + a[i].r[2].v;
//				dp[i][2].cnt[1] = dp[i - 1][3].cnt[1];
//				dp[i][2].cnt[2] = dp[i - 1][3].cnt[2];
//				dp[i][2].cnt[3] = dp[i - 1][3].cnt[3];
//				dp[i][2].cnt[a[i].r[2].id] = dp[i - 1][3].cnt[a[i].r[2].id] + 1;
//			}
//			
//			if (dp[i - 1][1].cnt[a[i].r[3].id] < maxv)
//			{
//				dp[i][3].v = dp[i - 1][1].v + a[i].r[3].v;
//				dp[i][3].cnt[1] = dp[i - 1][1].cnt[1];
//				dp[i][3].cnt[2] = dp[i - 1][1].cnt[2];
//				dp[i][3].cnt[3] = dp[i - 1][1].cnt[3];
//				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][1].cnt[a[i].r[3].id] + 1;
//			}
//			if (dp[i - 1][2].cnt[a[i].r[3].id] < maxv && (dp[i - 1][2].v + a[i].r[3].v > dp[i][3].v 
//                || (dp[i - 1][2].v + a[i].r[3].v == dp[i][3].v && 
//                (dp[i - 1][2].cnt[a[i].r[2].id] + 1 < dp[i][3].cnt[a[i].r[3].id] ||
//                 (dp[i - 1][2].cnt[1] < dp[i][3].cnt[1] && a[i].r[3].id != 1) || 
//                 (dp[i - 1][2].cnt[2] < dp[i][3].cnt[2] && a[i].r[3].id != 2) || 
//                 (dp[i - 1][2].cnt[3] < dp[i][3].cnt[3] && a[i].r[3].id != 3)))))
//			{
//				dp[i][3].v = dp[i - 1][2].v + a[i].r[3].v;
//				dp[i][3].cnt[1] = dp[i - 1][2].cnt[1];
//				dp[i][3].cnt[2] = dp[i - 1][2].cnt[2];
//				dp[i][3].cnt[3] = dp[i - 1][2].cnt[3];
//				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][2].cnt[a[i].r[3].id] + 1;
//			}
//			if (dp[i - 1][3].cnt[a[i].r[3].id] < maxv && (dp[i - 1][3].v + a[i].r[3].v > dp[i][3].v 
//                || (dp[i - 1][3].v + a[i].r[3].v == dp[i][3].v && 
//                (dp[i - 1][3].cnt[a[i].r[2].id] + 1 < dp[i][3].cnt[a[i].r[3].id] ||
//                 (dp[i - 1][3].cnt[1] < dp[i][3].cnt[1] && a[i].r[3].id != 1) || 
//                 (dp[i - 1][3].cnt[2] < dp[i][3].cnt[2] && a[i].r[3].id != 2) || 
//                 (dp[i - 1][3].cnt[3] < dp[i][3].cnt[3] && a[i].r[3].id != 3)))))
//			{
//				dp[i][3].v = dp[i - 1][3].v + a[i].r[3].v;
//				dp[i][3].cnt[1] = dp[i - 1][3].cnt[1];
//				dp[i][3].cnt[2] = dp[i - 1][3].cnt[2];
//				dp[i][3].cnt[3] = dp[i - 1][3].cnt[3];
//				dp[i][3].cnt[a[i].r[3].id] = dp[i - 1][3].cnt[a[i].r[3].id] + 1;
//			}
//		}
//		
//		printf("%d\n", max({dp[n][1].v, dp[n][2].v, dp[n][3].v}));
//	}
//}

#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

using ll = long long;

const ll N = 1e5 + 5, INF = 1e9;

struct Node
{
	ll v, id;
};

struct Human
{
	Node r[5];
	ll diff[5];
} a[N];

struct DP
{
	ll v, cnt[5];
} dp[N][5];

ll t, n, maxv;

inline void update(ll i, ll x, ll y)
{
    if (dp[i - 1][y].cnt[a[i].r[x].id] < maxv && (dp[i - 1][y].v + a[i].r[x].v > dp[i][x].v 
        || (dp[i - 1][y].v + a[i].r[x].v == dp[i][x].v && 
        (dp[i - 1][y].cnt[a[i].r[x].id] + 1 <= dp[i][x].cnt[a[i].r[x].id] &&
        (dp[i - 1][y].cnt[1] <= dp[i][x].cnt[1] && a[i].r[x].id != 1) && 
        (dp[i - 1][y].cnt[2] <= dp[i][x].cnt[2] && a[i].r[x].id != 2) && 
        (dp[i - 1][y].cnt[3] <= dp[i][x].cnt[3] && a[i].r[x].id != 3)))))
    {
        dp[i][x].v = dp[i - 1][y].v + a[i].r[x].v;

        dp[i][x].cnt[1] = dp[i - 1][y].cnt[1];
        dp[i][x].cnt[2] = dp[i - 1][y].cnt[2];
        dp[i][x].cnt[3] = dp[i - 1][y].cnt[3];

        dp[i][x].cnt[a[i].r[x].id] = dp[i - 1][y].cnt[a[i].r[x].id] + 1;

//		printf("    Dp %lld Successfully On %lld With cnt = %lld. v = %lld + %lld cnt = %lld\n", x, y, 
//				dp[i - 1][y].cnt[a[i].r[x].id], 
//				dp[i - 1][y].v, a[i].r[x].v, 
//				dp[i][x].cnt[a[i].r[x].id]);
    }
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%lld", &t);
	
	while (t --)
	{
		scanf("%lld", &n);
		maxv = n / 2;

		for (ll i = 1; i <= n; ++ i)
		{
			cin >> a[i].r[1].v >> a[i].r[2].v >> a[i].r[3].v;

			a[i].r[1].id = 1;
			a[i].r[2].id = 2;
			a[i].r[3].id = 3;

			sort(a[i].r + 1, a[i].r + 4, [&](const Node &x, const Node &y)
			{
				if (x.v != y.v)
				{
					return x.v > y.v;
				}
				return x.id < y.id;
			});
			
			a[i].diff[1] = a[i].r[1].v - a[i].r[2].v;
			a[i].diff[2] = a[i].r[2].v - a[i].r[3].v;

			dp[i][1].cnt[1] = dp[i][1].cnt[2] = dp[i][1].cnt[3] = 
			dp[i][2].cnt[1] = dp[i][2].cnt[2] = dp[i][1].cnt[3] = 
			dp[i][3].cnt[1] = dp[i][3].cnt[2] = dp[i][3].cnt[3] = INF;
            dp[i][1].v = dp[i][2].v = dp[i][3].v = 0;
		}
		
		sort(a + 1, a + n + 1, [&](const Human &x, const Human &y)
		{
			if (x.diff[1] != y.diff[1])
			{
				return x.diff[1] > y.diff[1];
			}
			else if (x.diff[2] != y.diff[2])
			{
				return x.diff[2] > y.diff[2];
			}
			else
			{
				if (x.r[1].v != y.r[1].v)
				{
					return x.r[1].v > y.r[1].v;
				}
				else if (x.r[2].v != y.r[2].v)
				{
					return x.r[2].v > y.r[2].v;
				}
				return x.r[3].v > y.r[3].v;
			}
//			if (x.r[1].v != y.r[1].v)
//			{
//				return x.r[1].v > y.r[1].v;
//			}
//			else if (x.r[2].v != y.r[2].v)
//			{
//				return x.r[2].v > y.r[2].v;
//			}
//			return x.r[3].v > y.r[3].v;
		});
		
//		for (int i = 1; i <= n; ++ i)
//		{
//			printf("[%d] %d(%d) %d(%d) %d(%d)\n", i, 
//			a[i].r[1].v, a[i].r[1].id, 
//			a[i].r[2].v, a[i].r[2].id, 
//			a[i].r[3].v, a[i].r[3].id);
//		}

		dp[1][a[1].r[1].id].v = a[1].r[1].v;
		dp[1][a[1].r[2].id].v = a[1].r[2].v;
		dp[1][a[1].r[3].id].v = a[1].r[3].v;

		dp[1][1].cnt[1] = dp[1][1].cnt[2] = dp[1][1].cnt[3] = 
		dp[1][2].cnt[1] = dp[1][2].cnt[2] = dp[1][1].cnt[3] = 
		dp[1][3].cnt[1] = dp[1][3].cnt[2] = dp[1][3].cnt[3] = 0;
	    dp[1][a[1].r[1].id].cnt[a[1].r[1].id] = dp[1][a[1].r[2].id].cnt[a[1].r[2].id] = dp[1][a[1].r[3].id].cnt[a[1].r[3].id] = 1;

		for (ll i = 2; i <= n; ++ i)
		{
//			printf("Dp [%lld]\n", i);
            for (ll x = 1; x <= 3; ++ x)
            {
//				printf("  Dp %lld -> %lld, %lld\n", x, a[i].r[x].v, a[i].r[x].id);
                for (ll y = 1; y <= 3; ++ y)
                {
                    update(i, x, y);
                }
            }
		}
		
		printf("%lld\n", max({dp[n][1].v, dp[n][2].v, dp[n][3].v}));
	}
}
