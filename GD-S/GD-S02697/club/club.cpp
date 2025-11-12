#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 1e5 + 5;

int T;
int n;
LL a[N][5];

priority_queue<pair<LL, int> > t1, t2, t3;
int cnt1, cnt2, cnt3;
LL res; 

void F()
{
	while (cnt1 > n / 2)
	{
		int x = t1.top().x, i = t1.top().y;
		t1.pop();
		
		cnt1 -- ;
		res += x;
	}
	while (cnt2 > n / 2)
	{
		int x = t2.top().x, i = t2.top().y;
		t2.pop();
		
		cnt2 -- ;
		res += x;
	}
	while (cnt3 > n / 2)
	{
		int x = t3.top().x, i = t3.top().y;
		t3.pop();
		
		cnt3 -- ;
		res += x;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while (T -- )
	{
		res = cnt1 = cnt2 = cnt3 = 0;
		while (!t1.empty()) t1.pop();
		while (!t2.empty()) t2.pop();
		while (!t3.empty()) t3.pop();
		
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		for (int i = 1; i <= n; i ++ ) 
		{
			int maxa = max(a[i][1], max(a[i][2], a[i][3]));
			if (maxa == a[i][1]) 
			{
				if (a[i][2] - a[i][1] > a[i][3] - a[i][1]) t1.push({a[i][2] - a[i][1], i});
				else t1.push({a[i][3] - a[i][1], i});
				res += a[i][1], cnt1 ++ ;
			}
			else if (maxa == a[i][2])
			{
				if (a[i][1] - a[i][2] > a[i][3] - a[i][2])t2.push({a[i][1] - a[i][2], i});
				else t2.push({a[i][3] - a[i][2], i});
				res += a[i][2], cnt2 ++ ;
			}
			else
			{
				if (a[i][1] - a[i][3] > a[i][2] - a[i][3]) t3.push({a[i][1] - a[i][3], i});
				else t3.push({a[i][2] - a[i][3], i});
				res += a[i][3], cnt3 ++ ;
			}
		}
		
		F();
		
		cout << res << '\n';
	}

	return 0;
}

