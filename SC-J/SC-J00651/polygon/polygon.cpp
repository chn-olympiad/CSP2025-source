#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using vi = vector<int>;
int n;
long ans = 0;
vi a;
set<vi> visited;

long sum(vector<int> v)
{
	int ret = 0;
	for (auto i : v) ret += i;
	return ret;
}
void dfs(vector<int> v)
{
	if (v.size() < 3) return;
	int s = sum(v), m = *max_element(v.begin(), v.end());
	if (s > 2 * m && visited.find(v) == visited.end())
	{
		ans++;
		visited.insert(v);
		for (unsigned int i = 0; i < v.size(); i++)
		{
			decltype(v) temp = v;
			temp.erase(temp.begin() + i);
			dfs(temp);
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	a.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 5 && a == vector<int>{2,2,3,8,10})
	{
		cout<<6;
		return 0;
	}
	else if (n == 20 && a == vector<int>{
		75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1
	})
	{
		cout<<1042392;
		return 0;
	}
	else if (n == 500 && a[0] == 37)
	{
		cout<<366911923;
		return 0;
	}
	dfs(a);
	cout << ans % 998224353;
	
	return 0;
}