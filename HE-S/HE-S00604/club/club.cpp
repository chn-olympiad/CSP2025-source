#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, ans, T;
struct E
{
	int a, b, c;
	void rrr()
	{
		scanf("%d %d %d", &a, &b, &c);
	}
}e[N];
void dfs(int s, int A, int B, int C, int sum)
{
	if(A > n / 2)return;
	if(B > n / 2)return;
	if(C > n / 2)return;
	if(s > n)
	{
		ans = max(ans, sum);
		return;
	}
	dfs(s + 1, A + 1, B, C, sum + e[s].a);
	dfs(s + 1, A, B + 1, C, sum + e[s].b);
	dfs(s + 1, A, B, C + 1, sum + e[s].c);
}
bool cmp(E x, E y)
{
	return x.a > y.a;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		ans = 0;
		for(int i = 1 ; i <= n ; i++)
			e[i].rrr();
		if(n < 200)dfs(1, 0, 0, 0, 0);
		else
		{
			sort(e + 1, e + n + 1, cmp);
			for(int i = 1 ; i <= n / 2 ; i++)
			{
				ans += e[i].a;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
