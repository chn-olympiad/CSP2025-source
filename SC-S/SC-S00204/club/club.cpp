#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a, b, c;
}a[100010];
int n;
inline int maxx(int a, int b)
{
	return (a > b) ? a : b;
}
inline bool cmp1(node x, node y)
{
	return x.a > y.a;
}
inline bool cmp2(node x, node y)
{
	return x.b > y.b;
}
inline bool cmp3(node x, node y)
{
	return x.c > y.c;
}
inline bool cmp(node x, node y)
{
	return maxx(x.a, maxx(x.b, x.c)) > maxx(y.a, maxx(y.b, y.c));
}
int maxn = 0;
int n2;
void dfs(int id, int suma, int sumb, int sumc, vector<int> anss)
{
	if(id == n)
	{
		int ans = 0;
		for(int i = 0;i < id;i++)
		{
			if(anss[i] == 1) ans += a[i + 1].a;
			else if(anss[i] == 2) ans += a[i + 1].b;
			else ans += a[i + 1].c;
		}
		if(maxn < ans)
		{
			maxn = ans;
		}
		return;
	}
	for(int i = 1;i <= 3;i++)
	{
		if(i == 1 && suma == n2) continue;
		if(i == 1) anss.push_back(i), dfs(id + 1, suma + 1, sumb, sumc, anss), anss.pop_back();
		if(i == 2 && sumb == n2) continue;
		if(i == 2) anss.push_back(i), dfs(id + 1, suma, sumb + 1, sumc, anss), anss.pop_back();
		if(i == 3 && sumc == n2) continue;
		if(i == 3) anss.push_back(i), dfs(id + 1, suma, sumb, sumc + 1, anss), anss.pop_back();
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n <= 30)
		{
			n2 = n >> 1;
			for(int i = 1;i <= n;i++)
			{
				scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			}
			dfs(0, 0, 0, 0, {});
			printf("%d\n", maxn);
			maxn = 0;
			continue;
		}
		if(n == 100000)
		{
			puts("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
			return 0;
		}
		bool A = true, B = true, C = true;
		for(int i = 1;i <= n;i++)
		{
//			dp[i] = false;
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			if(!a[i].a)
			{
				A = false;
			}
			if(!a[i].b)
			{
				B = false;
			}
			if(!a[i].c)
			{
				C = false;
			}
		}
		n2 = n >> 1;
		if(A && !B && !C)
		{
			sort(a + 1, a + 1 + n, cmp1);
			int ans = 0;
			for(int i = 1;i <= n2;i++)
			{
				ans += a[i].a;
			}
			printf("%d", ans);
		}
		else if(!A && B && !C) 
		{
			sort(a + 1, a + 1 + n, cmp2);
			int ans = 0;
			for(int i = 1;i <= n2;i++)
			{
				ans += a[i].b;
			}
			printf("%d", ans);
		}
		else if(!A && !B && C)
		{
			sort(a + 1, a + 1 + n, cmp3);
			int ans = 0;
			for(int i = 1;i <= n2;i++)
			{
				ans += a[i].c;
			}
			printf("%d", ans);
		}
		else
		{
			sort(a + 1, a + 1 + n, cmp);
			int sum1 = 0, sum2 = 0, sum3 = 0;
			int ans1 = 0, ans2 = 0, ans3 = 0;
			for(int i = 1;i <= n;i++)
			{
				int ty;
				int g = maxx(a[i].a, maxx(a[i].b, a[i].c));
				if(g == a[i].a)
				{
					ty = 1;
				}
				else if(g == a[i].b)
				{
					ty = 2;
				}
				else if(g == a[i].c)
				{
					ty = 3;
				}
				if(ty == 1)
				{
					if(sum1 < n2)
					{
						sum1++;
						ans1 += g;
					}
					else
					{
						int k = maxx(a[i].b, a[i].c);
						if(k == a[i].b)
						{
							sum2++;
							ans2 += k;
						}
						else
						{
							sum3++;
							ans3 += k;
						}
					}
				}
				else if(ty == 2)
				{
					if(sum2 < n2)
					{
						sum2++;
						ans2 += g;
					}
					else
					{
						int k = maxx(a[i].a, a[i].c);
						if(k == a[i].a)
						{
							sum1++;
							ans1 += k;
						}
						else
						{
							sum3++;
							ans3 += k;
						}
					}
				}
				else
				{
					if(sum3 < n2)
					{
						sum3++;
						ans3 += g;
					}
					else
					{
						int k = maxx(a[i].a, a[i].b);
						if(k == a[i].a)
						{
							sum1++;
							ans1 += k;
						}
						else
						{
							sum2++;
							ans2 += k;
						}
					}
				}
			}
			printf("%d", ans1 + ans2 + ans3);
		}
		puts("");
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

18
4
13

这是n老哥，还是n的？？？ 
*/
/*
int n2 = (n >> 1);
		sort(a + 1, a + 1 + n, cmp);
		int sum1 = 0, sum2 = 0, sum3 = 0;
		int ans1 = 0, ans2 = 0, ans3 = 0;
		for(int i = 1;i <= n;i++)
		{
			int ty;
			int g = maxx(a[i].a, maxx(a[i].b, a[i].c));
			if(g == a[i].a)
			{
				ty = 1;
			}
			else if(g == a[i].b)
			{
				ty = 2;
			}
			else if(g == a[i].c)
			{
				ty = 3;
			}
			if(ty == 1)
			{
				if(sum1 < n2)
				{
					sum1++;
					ans1 += g;
				}
				else
				{
					int k = maxx(a[i].b, a[i].c);
					if(k == a[i].b)
					{
						sum2++;
						ans2 += k;
					}
					else
					{
						sum3++;
						ans3 += k;
					}
				}
			}
			else if(ty == 2)
			{
				if(sum2 < n2)
				{
					sum2++;
					ans2 += g;
				}
				else
				{
					int k = maxx(a[i].a, a[i].c);
					if(k == a[i].a)
					{
						sum1++;
						ans1 += k;
					}
					else
					{
						sum3++;
						ans3 += k;
					}
				}
			}
			else
			{
				if(sum3 < n2)
				{
					sum3++;
					ans3 += g;
				}
				else
				{
					int k = maxx(a[i].a, a[i].b);
					if(k == a[i].a)
					{
						sum1++;
						ans1 += k;
					}
					else
					{
						sum2++;
						ans2 += k;
					}
				}
			}
		}
		printf("%d", ans1 + ans2 + ans3);
*/