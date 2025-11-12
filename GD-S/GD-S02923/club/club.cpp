#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int ans;
int res;
int num[10];

struct opinion{
	int a, b, c;
} people[100005];

bool cmp(opinion a, opinion b)
{
	return (a.a + a.b + a.c) > (b.a + b.b + b.c);
}

void dfs(int dep)
{
	if (dep > n)
	{
		ans = max(ans, res);
		return ;
	}
	
	for (int i = 1; i <= 3; i++)
	{
		if (num[i] >= n / 2) continue;
		int sym;
		if (i == 1) sym = people[dep].a;
		else if (i == 2) sym = people[dep].b;
		else sym = people[dep].c; 
		num[i]++;
		res += sym;
		dfs(dep + 1);
		num[i]--;
		res -= sym;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> people[j].a >> people[j].b >> people[j].c;
		}
//		sort(people + 1, people + n + 1, cmp);
		ans = 0;
		res = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}

