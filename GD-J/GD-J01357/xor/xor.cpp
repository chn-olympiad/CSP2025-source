#include<bits/stdc++.h>
#define twin pair<int, int>

using namespace std;
const int N = 5e5+1;
map<long long, vector<twin> > ans;
int n, k;
long long pre[N], cnt;
int cmp(twin x, twin y)
{
	if(x.second==y.second)
	{
		return x.first>y.first;
	}
	return x.second<y.second;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1, x; i <= n; i++)
	{
		cin >> x;
		for(int j = 1; j <= i; j++)
		{
			pre[j] ^= x;
			ans[pre[j]].push_back({j, i});
		}
	}
	if(ans[k].size())
	{
		sort(ans[k].begin(), ans[k].end(), cmp);
		int max_r = -1;
		for(auto i : ans[k])
		{
			if(max_r<i.first)
			{
				cnt++;
				max_r = i.second;
			}
		}
	}
	cout << cnt;
	
	return 0;
}
