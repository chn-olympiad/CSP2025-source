#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 1e5 + 5;

struct node
{
	int id, d;
	LL sum;
} st[N];

int t, n, maxn, a[5][N], cnt[5];
LL ans = 0;

bool cmp(node x, node y)
{
	return x.sum > y.sum;
}
vector<pair<LL, int> > p;

void dfs(int id, int d, LL sum)
{
	if(id == n + 1) 
	{
		ans = max(ans, sum);
		return ;
	}
	
	cnt[d]++;
	
	for(int i = 1; i <= 3; i++)
	{
		if(cnt[i] >= maxn) continue;
		dfs(id + 1, i, sum + a[i][id + 1]);
	}
	
	cnt[d]--;
}

void work()
{
	int z = 0;
	ans = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 3; j++)
		{
			cin >> a[j][i];
			if(a[j][i] == 0) z++;
		}
		
	maxn = (n >> 1);
	
	if(z >= n * 2) 
	{
		sort(a[1] + 1, a[1] + n + 1);
		for(int i = n; i > maxn; i--)
		{
			ans += a[1][i];
		}
		cout << ans << "\n";
		return ;
	}
			
	for(int i = 1; i <= 3; i++)
		dfs(1, i, a[i][1]);		
	
	
	cout << ans << "\n";
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	cin >> t;
	while(t--) work();
	return 0;
}
