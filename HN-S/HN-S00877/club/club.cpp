#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, mod = 0;
struct E
{
	int id, val;
	bool operator <(const E &tmp)const
	{
		return val < tmp.val;
	}
};
priority_queue<E> pq1, pq2;
struct node
{
	int a, b, c;
}a[N];
int n, asa, asb, asc;
int calc(int i, int d)
{
	if(d == 1) return a[i].a;
	if(d == 2) return a[i].b;
	if(d == 3) return a[i].c;
}
int dfs(int cur, int a, int b, int c, int d)
{
	int sum = 0;
	if(cur == n + 1) return 0;
	if(a < n / 2)
		sum = max(sum, dfs(cur + 1, a + 1, b, c, 1));
	if(b < n / 2)
		sum = max(sum, dfs(cur + 1, a, b + 1, c, 2));
	if(c < n / 2)
		sum = max(sum, dfs(cur + 1, a, b, c + 1, 3));
	sum += calc(cur, d);
	return sum;
}
int work()
{
	asa = asb = asc = 0;
	int cnta = 0, cntb = 0, cntc = 0;
	cin >> n;
	if(n <= 30)
	{
		for(int i = 1; i <= n; i++)
			cin >> a[i].a >> a[i].b >> a[i].c;
		asa = max(dfs(1, 1, 0, 0, 1), max(dfs(1, 0, 1, 0, 2), dfs(1, 0, 0, 1, 3)));
		return asa;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;	
		if(a[i].a >= a[i].b && a[i].a >= a[i].c)
		{
			if(cnta < n / 2) asa += a[i].a, cnta++, pq1.push({i, a[i].b - a[i].a});
			else
			{
				if(a[i].b >= a[i].c && cntb < n / 2)
					asb += a[i].b, cntb++, pq2.push({i, a[i].a - a[i].b});
				else
					asc += a[i].c, cntc++;
			}
		} else if(a[i].b >= a[i].c && cntb < n / 2)
			asb += a[i].b, cntb++;
		else
			asc += a[i].c, cntc++;
	}
	if(cntc == 0) 
	{
		while(!pq1.empty() || !pq2.empty())
		{
			E c1 = pq1.top();
			E c2 = pq2.top();
			pq1.pop();
			pq2.pop();
			if(c1.val + c2.val > 0)
			{
				asa += c1.val;
				asb += c2.val;
				pq1.push({c2.id, -c2.val});
				pq2.push({c1.id, -c1.val});
			} else
				break;
		}
	}
	return asa + asb + asc;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		cout << work() << '\n';
	return 0;
}
