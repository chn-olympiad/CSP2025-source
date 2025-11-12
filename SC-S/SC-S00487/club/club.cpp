#include<bits/stdc++.h>
#define ll long long
#define furina puts("QAQ");
using namespace std;
const int maxn = 1e5 + 5;

int T; 
int n;
bool flag;

ll sum[10];

priority_queue<pair<int, int> > q[10];

struct Member
{
	int a1;
	int a2;
	int a3;
	
	int att;
	int maxx;
	int nexx;
}a[maxn];


void solve(int loc)
{
	if (a[loc].a1 >= a[loc].a2 && a[loc].a1 >= a[loc].a3)
	{
		a[loc].maxx = a[loc].a1;
		a[loc].nexx = max (a[loc].a2, a[loc].a3);
		if (a[loc].a2 > a[loc].a3) a[loc].att = 2;
		else a[loc].att = 3;
		
		if (q[1].size() >= n / 2)	
		{
			int x = -q[1].top().first;
			int pos = q[1].top().second;
			
			if (x < a[loc].maxx - a[loc].nexx)
			{
				sum[1] -= a[pos].maxx;
				sum[1] += a[loc].maxx;
				
				sum[a[pos].att] += a[pos].nexx; 
				q[1].pop();
				q[1].push({-a[loc].maxx + a[loc].nexx, loc});
			}	
			else
			{
				sum[a[loc].att] += a[loc].nexx; 
			}		
		}
		else
		{
			q[1].push({-a[loc].maxx + a[loc].nexx, loc});
			sum[1] += a[loc].maxx;
		}
	}
	else if(a[loc].a2 >= a[loc].a1 && a[loc].a2 >= a[loc].a3)
	{
		a[loc].maxx = a[loc].a2;
		a[loc].nexx = max (a[loc].a1, a[loc].a3);
		if (a[loc].a1 > a[loc].a3) a[loc].att = 1;
		else a[loc].att = 3;
		
		if (q[2].size() >= n / 2)	
		{
			int x = -q[2].top().first;
			int pos = q[2].top().second;
			
			if (x < a[loc].maxx - a[loc].nexx)
			{
				sum[2] -= a[pos].maxx;
				sum[2] += a[loc].maxx;
				
				sum[a[pos].att] += a[pos].nexx; 
				q[2].pop();
				q[2].push({-a[loc].maxx + a[loc].nexx, loc});
			}	
			else
			{
				sum[a[loc].att] += a[loc].nexx; 
			}		
		}
		else
		{
			q[2].push({-a[loc].maxx + a[loc].nexx, loc});
			sum[2] += a[loc].maxx;
		}
	}
	else
	{
		a[loc].maxx = a[loc].a3;
		a[loc].nexx = max (a[loc].a1, a[loc].a2);
		if (a[loc].a1 > a[loc].a2) a[loc].att = 1;
		else a[loc].att = 2;
		
		if (q[3].size() >= n / 2)	
		{
			int x = -q[3].top().first;
			int pos = q[3].top().second;
			
			if (x < a[loc].maxx - a[loc].nexx)
			{
				sum[3] -= a[pos].maxx;
				sum[3] += a[loc].maxx;
				
				sum[a[pos].att] += a[pos].nexx; 
				q[3].pop();
				q[3].push({-a[loc].maxx + a[loc].nexx, loc});
			}	
			else
			{
				sum[a[loc].att] += a[loc].nexx; 
			}		
		}
		else
		{
			q[3].push({-a[loc].maxx + a[loc].nexx, loc});
			sum[3] += a[loc].maxx;
		}
	}
}

signed main()
{
//	system("fc furina.out club2.ans");
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club2.in", "r", stdin);
//	freopen("furina.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		flag = 0;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= 3; i++)
		{
			while (!q[i].empty())
			{
				q[i].pop();
			}
		}
		
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;

			if (flag) 
			{
				solve(i);
				continue;
			}
			
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3)
			{	
				a[i].maxx = a[i].a1;
				a[i].nexx = max (a[i].a2, a[i].a3);
				if (a[i].a2 > a[i].a3) a[i].att = 2;
				else a[i].att = 3;
				
				q[1].push({-a[i].maxx + a[i].nexx, i});
				sum[1] += a[i].maxx;
				
				if (q[1].size() >= n / 2) flag = 1;
			}
			else if(a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)
			{
				a[i].maxx = a[i].a2;
				a[i].nexx = max (a[i].a1, a[i].a3);
				if (a[i].a1 > a[i].a3) a[i].att = 1;
				else a[i].att = 3;
				
				q[2].push({-a[i].maxx + a[i].nexx, i});
				sum[2] += a[i].maxx;
				
				if (q[2].size() >= n / 2) flag = 1;
			}
			else
			{
				a[i].maxx = a[i].a3;
				a[i].nexx = max (a[i].a1, a[i].a2);
				if (a[i].a2 > a[i].a1) a[i].att = 2;
				else a[i].att = 1;
				
				q[3].push({-a[i].maxx + a[i].nexx, i});
				sum[3] += a[i].maxx;
				
				if (q[3].size() >= n / 2) flag = 1;
			}
		}
		
		ll ans = 0;
		for (int i = 1; i <= 3; i++)
		{
			ans += sum[i];
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
// dp ? O（nlogn）/ O(nlogn^2) 
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