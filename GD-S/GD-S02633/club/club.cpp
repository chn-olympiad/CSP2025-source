#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, inf = 2e9 + 7;
struct node
{
	int x, y, z;
}a[N];
int n, cnt1, cnt2, cnt3, ch[N], A[N], B[N], C[N];
bool cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cnt1 = cnt2 = cnt3 = 0;
		scanf("%d", &n);//cin >> n;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);//cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z)
			{
				cnt1++;
				ch[i] = 1;
				A[i] = min(a[i].x - a[i].y, a[i].x - a[i].z);
				B[i] = C[i] = inf;
			}
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z)
			{
				cnt2++;
				ch[i] = 2;
				B[i] = min(a[i].y - a[i].x, a[i].y - a[i].z);
				A[i] = C[i] = inf;
			}
			else if(a[i].z >= a[i].y && a[i].z >= a[i].x)
			{
				cnt3++;
				ch[i] = 3;
				C[i] = min(a[i].z - a[i].y, a[i].z - a[i].x);
				B[i] = A[i] = inf;
			}
			ans += max(a[i].x, max(a[i].y, a[i].z));
		}
		if(cnt1 > n / 2)
		{
			sort(A + 1, A + 1 + n);
			for(int i = 1; i <= cnt1 - n / 2; i++)
			{
				ans -= A[i];
			}
		}
		else if(cnt2 > n / 2)
		{
			sort(B + 1, B + 1 + n);
			for(int i = 1; i <= cnt2 - n / 2; i++)
			{
				ans -= B[i];
			}
		}
		else if(cnt3 > n / 2)
		{
			sort(C + 1, C + 1 + n);
			for(int i = 1; i <= cnt3 - n / 2; i++)
			{
				ans -= C[i];
			}
		}
		printf("%d\n", ans);
	}
}
