#include <iostream>
#include <map>
using namespace std;
int l[5000], n;
struct arg
{
	int from, sum, mxv;
};
bool operator<(arg a, arg b)
{
	if (a.from == b.from)
	{
		if (a.sum == b.sum)
		{
			return a.mxv < b.mxv;
		}
		else return a.sum < b.sum;
	}
	else return a.from < b.from;
}
map <arg, int> f;
int func(int from, int& depth, int& sum, int& mxv)
{
	if (from == n-1) return 0;
	int ans = 0;
	//cout << string(depth, ' ') << from << ',' << sum << ',' << mxv << endl;
	++depth;
	//if (depth >= 3 && f[{from, sum, mxv}]) return f[{from, sum, mxv}];
	for (int i = ++from; i < n; ++i)
	{
		int a = sum + l[i], b = max(mxv, l[i]);
		ans += func(i, depth, a, b);
		if (depth >= 3 && a > 2 * b) ++ans;
	}
	--depth;
	return ans;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i];
	}
	int depth = 0, sum = 0, mxv = 0;
	cout << func(-1, depth, sum, mxv);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
