#include <iostream>
#include <vector>
using namespace std;
vector<int> l;
vector<pair<int, int>> u;
int xlr(int l, int r)
{
	if(l == r)
		return ::l[l];
	int ans = ::l[l];
	for(int i = l; i < r; i++)
		ans = (ans ^ ::l[i + 1]);
	return ans;
}
bool cu(int le, int ri)
{
	for(auto a : u)
		if(le - a.second <= 0)
			return 0;
	return 1;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		l.push_back(x);
	}
	for(int i = 0; i <= n; i++)
		for(int j = i; j <= n; j++)
			if(xlr(i, j) == k)
			{
				if(u.empty())
				{
					u.push_back({i, j});
					cnt++;
				}
				if(cu(i, j))
				{
					u.push_back({i, j});
					cnt++;
				}
			}
	int cnt2 = 0;
	for(int a : l)
		if(a == k)
			cnt2++;
	cout << max(cnt, cnt2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}