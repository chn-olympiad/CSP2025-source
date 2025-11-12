#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int t, n, ans;
int vis[N];
int sum[N];
//pair<int,int> a[N], b[N], c[N];
int a[N][5];
//priority_queue<pair<int,int>> q1, q2, q3;
int s[4];

void dfs(int k)
{
	
	if(k>n)
	{
//		int res=0;
//		for(int i=1; i<=n; i++)
//		res+=a[i][vis[i]];
//		if(res<=ans) return;
//		for(int i=1; i<=n; i++)
//		printf("%d ", vis[i]);
//		putchar('\n');
		ans=max(ans, sum[k-1]);
		return;
	}
	for(int i=1; i<=3; i++)
	{
		if(s[i]*2>=n) continue;
		s[i]++;
		vis[k]=i;
		sum[k]=sum[k-1]+a[k][i];
//		for(int i=1; i<=n; i++)
//		printf("%d ", vis[i]);
//		printf("%d %d %d\n", k, i, s[i]);
//		printf("%d\n", k);
		dfs(k+1);
		s[i]--;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	scanf("%d", &t);
	while(t--)
	{
		ans=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		dfs(1);
		printf("%d\n", ans);
	}
} 
