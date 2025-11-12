#include <bits/stdc++.h>
using namespace std;
int t, n, a[100009][4], maxn = -1e9;
bool b[100009];
int cnt[4], s[100009];
void dfs(int k, int sum)
{
	if(k == n)
	{
		maxn = max(maxn, sum);
		//cout << sum << "\n";
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == 0)
		{
			b[i] = 1;
			for(int j = 1; j <= 3; j++)
			{
				if(cnt[j]+1 <= n/2.0){
					//cout << "选择" << j << " 当前人数" <<  cnt[j] << endl;
					cnt[j]++;
					dfs(k+1, sum + a[i][j]);
					cnt[j]--;
				}
			}
			b[i] = 0;
		}
	}
}
//void dfs2(int k, int sum)
//{
//	if(k == n)
//	{
//		maxn = max(maxn, sum);
//		//cout << sum << "\n";
//	}
//	for(int i = 1; i <= n; i++)
//	{
//		if(b[i] == 0)
//		{
//			b[i] = 1;
//			for(int j = 1; j <= 2; j++)
//			{
//				if(cnt[j]+1 <= n/2.0){
//					//cout << "选择" << j << " 当前人数" <<  cnt[j] << endl;
//					cnt[j]++;
//					dfs2(k+1, sum + a[i][j]);
//					cnt[j]--;
//				}
//			}
//			b[i] = 0;
//		}
//	}
//}
bool cmp(int x, int y) {
	return x > y;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >>t;
	while(t--)
	{
		cin >> n;
		bool flag = 1, flag2 = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				scanf("%d", &a[i][j]);
				s[i] = a[i][1];
				if(j!=1&&a[i][j]!=0) flag = 0;
			}
		}
		if(flag)
		{
			sort(s+1, s+1+n, cmp);
			maxn = 0;
			for(int i = 1; i <= n/2; i++) maxn += s[i];
		}
		else dfs(0, 0);
		cout << maxn << endl;
		maxn = -1e9;
	}
	
	return 0;
}

