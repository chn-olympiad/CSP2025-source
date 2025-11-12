#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define pb push_back
#define mp make_pair
#define f(s, i, x, y) for(s i = x; i <= y; i++)
typedef long long ll;
const int N = 1e5+5;
struct g{
	int id, val;
};
int n, a[N], b[N], c[N];
ll ans;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		ans = 0;
		vector<g> la, lb, lc;
		cin >> n;
		f(int, i, 1, n)
		{
			cin >> a[i] >> b[i] >> c[i];
			int tmax = max(a[i], max(b[i], c[i]));
			if(tmax == a[i])
			{
				if(la.size() < n/2)
					la.push_back({i, a[i]});
				else
				{
					int dir = 0, pos = 0, mx = 0;
					for(int j = 0; j < la.size(); j++)
					{
						int sum1 = b[i], sum2 = c[i];
						int s1 = b[la[j].id] + a[i] - la[j].val, s2 = c[la[j].id] + a[i] - la[j].val;
						if(s1 > mx) mx = s1,pos = j,dir = 1;
						if(sum1 > mx) mx = sum1,pos = j,dir = 2;
						if(s2 > mx) mx = s2,pos = j,dir = 3;
						if(sum2 > mx) mx = s2,pos = j,dir = 4;
					}
					if(dir == 1) lb.push_back({la[pos].id, b[la[pos].id]}), la.push_back({i, a[i]}), la.erase(la.begin()+pos);
					if(dir == 2) lb.push_back({i, b[i]});
					if(dir == 3) lc.push_back({la[pos].id, c[la[pos].id]}), la.push_back({i, a[i]}), la.erase(la.begin()+pos);
					if(dir == 4) lc.push_back({i, c[i]});
				}
			}
			else if(tmax == b[i])
			{
				if(lb.size() < n/2)
					lb.push_back({i, b[i]});
				else
				{
					int dir = 0, pos = 0, mx = 0;
					for(int j = 0; j < lb.size(); j++)
					{
						int sum1 = a[i], sum2 = c[i];
						int s1 = a[lb[j].id] + b[i] - lb[j].val, s2 = c[lb[j].id] + b[i] - lb[j].val;
						if(s1 > mx) mx = s1,pos = j,dir = 1;
						if(sum1 > mx) mx = sum1,pos = j,dir = 2;
						if(s2 > mx) mx = s2,pos = j,dir = 3;
						if(sum2 > mx) mx = s2,pos = j,dir = 4;
					}
					if(dir == 1) la.push_back({lb[pos].id, a[lb[pos].id]}), lb.push_back({i, b[i]}), lb.erase(lb.begin()+pos);
					if(dir == 2) la.push_back({i, a[i]});
					if(dir == 3) lc.push_back({lb[pos].id, c[lb[pos].id]}), lb.push_back({i, b[i]}), lb.erase(lb.begin()+pos);
					if(dir == 4) lc.push_back({i, c[i]});
				}
			}
			else
			{
				if(lc.size() < n/2)
					lc.push_back({i, c[i]});
				else
				{
					int dir = 0, pos = 0, mx = 0;
					for(int j = 0; j < lc.size(); j++)
					{
						int sum1 = b[i], sum2 = a[i];
						int s1 = b[lc[j].id] + c[i] - lc[j].val, s2 = a[lc[j].id] + c[i] - lc[j].val;
						if(s1 > mx) mx = s1,pos = j,dir = 1;
						if(sum1 > mx) mx = sum1,pos = j,dir = 2;
						if(s2 > mx) mx = s2,pos = j,dir = 3;
						if(sum2 > mx) mx = s2,pos = j,dir = 4;
					}
					if(dir == 1) lb.push_back({lc[pos].id, b[lc[pos].id]}), lc.push_back({i, c[i]}), lc.erase(lc.begin()+pos);
					if(dir == 2) lb.push_back({i, b[i]});
					if(dir == 3) la.push_back({lc[pos].id, a[lc[pos].id]}), lc.push_back({i, c[i]}), lc.erase(lc.begin()+pos);
					if(dir == 4) la.push_back({i, a[i]});
				}
			}
		}
		for(auto i : la) ans += i.val;
		for(auto i : lb) ans += i.val;
		for(auto i : lc) ans += i.val;
		cout << ans << endl;
	}
	return 0;
}
