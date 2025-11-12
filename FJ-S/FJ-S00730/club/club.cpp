#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n, t;

struct node
{
	int z, id;
}a[N][4];

bool cmp(node x, node y)
{
	return x.z > y.z;
}

bool cmp1(int i, int j)
{
	return a[i][1].z - a[i][2].z < a[j][1].z - a[j][2].z;
}

int q[4][N], cnt[4];

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t -- )
	{
		int ans = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= 3; j ++ )
				scanf("%lld", &a[i][j].z), a[i][j].id = j;
		for(int i = 1; i <= 3; i ++ )
			cnt[i] = 0;
		for(int i = 1; i <= n; i ++ )
		{
			sort(a[i] + 1, a[i] + 3 + 1, cmp);
			q[a[i][1].id][++ cnt[a[i][1].id]] = i;
			ans += a[i][1].z;
		}
		int pos = 0;
		for(int i = 1; i <= 3; i ++ )	
			if(cnt[i] > n / 2)
			{
				pos = i;
				break;
			}
		sort(q[pos] + 1, q[pos] + cnt[pos] + 1, cmp1);
		for(int i = 1; i <= cnt[pos] - n / 2; i ++ )
			ans = ans + a[q[pos][i]][2].z - a[q[pos][i]][1].z;
		cout << ans << endl; 
	}
	return 0;
}
