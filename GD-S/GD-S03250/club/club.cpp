#include <iostream>

#include <queue>

#define int long long

using namespace std;

const int N = 1e5 + 7;

struct P
{
	int a[5], x[5] = {0, 1, 2, 3};
	
	int cha;
}num[N];

int T;

int n;

struct L
{
	int a, po;
	
	bool operator <(const L &m)const
	{
		return a > m.a;
	}
};

priority_queue<L> q[5];

signed main()
{
	ios::sync_with_stdio(0);
	
	cin.tie(0), cout.tie(0);
	
	freopen("club.in", "r", stdin);
	
	freopen("club.out", "w", stdout);
	
	cin >> T;
	
	while(T --)
	{
		cin >> n;
		
		for(int k = 1; k <= 3; k ++)
			while(!q[k].empty())
				q[k].pop();
		
		for(int i = 1; i <= n; i ++)
		{
			for(int k = 1; k <= 3; k ++)
				cin >> num[i].a[k], num[i].x[k] = k;
			
			int ax = max(num[i].a[1], max(num[i].a[2], num[i].a[3]));
			
			for(int k = 2; k <= 3; k ++)
				if(ax == num[i].a[k])
				{
					swap(num[i].a[1], num[i].a[k]), swap(num[i].x[1], num[i].x[k]);
					
					break;
				}
			
			if(num[i].a[2] < num[i].a[3])
				swap(num[i].a[2], num[i].a[3]), swap(num[i].x[2], num[i].x[3]);
			
			num[i].cha = num[i].a[1] - num[i].a[2];
		}
		
		int cnt[5] = {0, 0, 0, 0}, sum = 0;
		
		for(int i = 1; i <= n; i ++)
		{
			if(cnt[num[i].x[1]] < n / 2)
			{
				cnt[num[i].x[1]] ++;
				
				sum += num[i].a[1];
				
				q[num[i].x[1]].push({num[i].cha, i});
			}
			else
			{
				q[num[i].x[1]].push({num[i].cha, i});
				
				int nm = q[num[i].x[1]].top().a, position = q[num[i].x[1]].top().po;
				
				q[num[i].x[1]].pop();
				
				sum -= nm, sum += num[i].a[1];
				
				cnt[num[position].x[2]] ++;
			}
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}
