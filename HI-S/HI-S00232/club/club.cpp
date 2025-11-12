#include<bits/stdc++.h>
using namespace std;
long long stu[100005][5], gooda[100005], maxn = -1, rem[100005];
int n;
void dfs(int step, int final, long long cnt, int cluba, int clubb, int clubc, int to_club)
{
//	if(rem[step])return rem[step];
	if(step > final)
	{
		maxn = max(maxn, cnt);
		return /*cnt*/;
	}
//	long long cho1, cho2, cho3;
	if(cluba + 1 <= n / 2)/*cho1 = */dfs(step + 1, final, cnt + stu[step][1], cluba + 1, clubb, clubc, 1);
	if(clubb + 1 <= n / 2)/*cho2 = */dfs(step + 1, final, cnt + stu[step][2], cluba, clubb + 1, clubc, 2);
	if(clubc + 1 <= n / 2)/*cho3 = */dfs(step + 1, final, cnt + stu[step][3], cluba, clubb, clubc + 1, 3);
	return /*rem[step] = max(cho1, max(cho2, cho3))*/;
}
void dfs2(int step, int final, long long cnt, int cluba, int clubb)
{
	if(step > final)
	{
		maxn = max(maxn, cnt);
		return;
	}
	if(cluba + 1 <= n / 2)dfs2(step + 1, final, cnt + stu[step][1], cluba + 1, clubb);
	if(clubb + 1 <= n / 2)dfs2(step + 1, final, cnt + stu[step][2], cluba, clubb + 1);
	return;
}
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t --)
	{
		
		cin >> n;
		bool A = 1, B = 1;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld", &stu[i][1]);
			gooda[i] = stu[i][1];
			for(int j = 2; j <= 3; j ++)
			{
				scanf("%lld", &stu[i][j]);
				if(stu[i][j])
				{
					A = 0;
					if(j == 3)B = 0; 
				}
			}
		}
		if(n <= 30)
		{
			maxn = -1;
			dfs(1, n, 0, 0, 0, 0, 0);
			printf("%lld\n", maxn);
		}
		else if(A)
		{
			sort(gooda + 1, gooda + n + 1, cmp);
			int ans = 0;
			for(int i = 1; i <= n / 2; i ++)ans += gooda[i];
			printf("ans\n");
		}
		else if(B)
		{
			maxn = -1;
			dfs2(1, n, 0, 0, 0);
			printf("%lld\n", maxn);
		}
	}
//	for(int i = 1; i <= n; i ++)
//	{
//		cout << rem[i] << ' ';
//	}
	return 0;
}
