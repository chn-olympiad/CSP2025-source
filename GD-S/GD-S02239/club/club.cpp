#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t;
int n;
int ans;
struct Node
{
	int x, y, z;
};
Node a[N];
void dfs(int tot, int val, int sa, int sb, int sc)
{
//	cout << tot << endl;
	if (tot == n)
	{
		ans = max(ans, val);
		return;
	}
	if (sa < n / 2) dfs(tot + 1, val + a[tot + 1].x, sa + 1, sb, sc);
	if (sb < n / 2) dfs(tot + 1, val + a[tot + 1].y, sa, sb + 1, sc);
	if (sc < n / 2) dfs(tot + 1, val + a[tot + 1].z, sa, sb, sc + 1);
}
//bool cmp(Node A, Node B)
//{
//	return max({A.x, A.y, A.z}) > max({B.x, B.y, B.z});
//}
//bool cmpa(Node A, Node B)
//{
//	return max(A.y, A.z) > max(B.y, B.z);
//}
//bool cmpb(Node A, Node B)
//{
//	return max(A.x, A.z) > max(B.x, B.z);
//}
//bool cmpc(Node A, Node B)
//{
//	return max(A.x, A.y) > max(B.x, B.y);
//}
//void noa(int i)
//{
//	cout << "a" << endl;
//	sort (a + i, a + 1 + n, cmpa);
//	for (i; i <= n; i++)
//	{
//		if (a[i].y >= a[i].z) ans += a[i].y;
//		else ans += a[i].z;
//	}
//	return;
//}
//void nob(int i)
//{
//	cout << "b" << endl;
//	sort (a + i, a + 1 + n, cmpb);
//	for (i; i <= n; i++)
//	{
//		if (a[i].x >= a[i].z) ans += a[i].x;
//		else ans += a[i].z;
//	}
//	return;
//}
//void noc(int i)
//{
//	cout << "c" << endl;
//	sort (a + i, a + 1 + n, cmpc);
//	for (i; i <= n; i++)
//	{
//		if (a[i].x >= a[i].y) ans += a[i].x;
//		else ans += a[i].y;
//	}
//	return;
//}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		}
		dfs(0, 0, 0, 0, 0);
//		for (int i = 1; i <= n; i++)
//		{
//			tmp = max({a[i].x, a[i].y, a[i].z});
//			ans += tmp;
//			if (tmp == a[i].x)
//			{
//				if (tmp == a[i].y)
//				{
//					if (tmp == a[i].z)
//					{
//						tmp = min({suma, sumb, sumc});
//						if (tmp == suma) suma++;
//						else if(tmp == sumb) sumb++;
//						else sumc++;
//					}
//					else
//					{
//						if (suma < sumb) suma++;
//						else sumb++;
//					}
//				}
//				else suma++;
//			}
//			else if (tmp == a[i].y)
//			{
//				if (tmp == a[i].z)
//				{
//					if (sumb < sumc) sumb++;
//					else sumc++;
//				}
//				else sumb++;
//			}
//			else sumc++;
//			tmp = max({suma, sumb, sumc});
//			if (tmp > n / 2)
//			{
//				cout << "in";
//				ans -= max({a[i].x, a[i].y, a[i].z});
//				if (tmp == suma) noa(i);
//				if (tmp == sumb) nob(i);
//				if (tmp == sumc) noc(i);
//				break;
//			}
//		}
		printf ("%d\n", ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
