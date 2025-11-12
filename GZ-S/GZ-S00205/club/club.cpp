// GZ-S00205 盘州市第二中学 曹立桐 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
typedef long long LL;

int T;
int n;
LL ans = 0;
LL ans2 = 0;
struct node
{
	int a, b, c;
}p[N];
LL f[210][70][70][70];

int dfs(int u, int cnt1, int cnt2, int cnt3, LL sum)
{
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return 0;
	if(cnt1 + cnt2 + cnt3 > n) return 0;
	if(f[u][cnt1][cnt2][cnt3]) return f[u][cnt1][cnt2][cnt3];
	if(u == n + 1) 
	{
		f[n][cnt1][cnt2][cnt3] = sum;
		ans = max(ans, sum);
		return 0;
	}
	
	dfs(u + 1, cnt1 + 1, cnt2, cnt3, sum + p[u].a);
	dfs(u + 1, cnt1, cnt2 + 1, cnt3, sum + p[u].b);
	dfs(u + 1, cnt1, cnt2, cnt3 + 1, sum + p[u].c);
	
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	
	while(T --)
	{
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		ans = 0;
		ans2 = 0;
		
		scanf("%d", &n);
		
			for(int i = 1; i <= n; i ++)
			{
				int a, b, c;
				scanf("%d%d%d", &a, &b, &c);
				p[i] = {a, b, c};
				int maxn = max(a, max(b, c));
				ans2 += maxn;
				if(a == maxn) cnt1 ++;
				else if(b == maxn) cnt2 ++;
				else cnt3 ++;
			}
			
			if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
			{
				printf("%lld\n", ans2);
				continue;
			}
			else cnt1 = cnt2 = cnt3 = 0;
			
			dfs(1, cnt1, cnt2, cnt3, 0);
			
			printf("%lld\n", ans);
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
