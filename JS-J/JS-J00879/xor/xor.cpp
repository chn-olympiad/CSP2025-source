#include <bits/stdc++.h>
typedef long long lng;
using namespace std;
const lng man = 5e5 + 5;
int a[man], b[man];
lng read()
{
	int x = 0, f = 1;
	char op = getchar();
	while(!isdigit(op))
	{
		if(op == '-') f = -1;
		op = getchar();
	}
	while(isdigit(op))
	{
		x = (x << 3) + (x << 1) + op - '0';
		op = getchar();
	}
	;
	return (x *= f);
}
struct qujian
{
	int l, r;
	qujian(const int &s = 0, const int &e = 0) : l(s), r(e) {}
	bool operator <(const qujian &x)const
	{
		if(r - l != x.r - x.l) return r - l < x.r - x.l;
		return l < x. l;
	}
	void operator =(const qujian &x) {l = x.l, r = x.r;}
};
vector<qujian> v, res;
bool check(const qujian &x)
{
	for(qujian &y : res)
		if(x.l <= y.r && x.r >= y.l) return 0;
	return 1;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	n = read(), k = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
		b[i] = b[i - 1] ^ a[i];
	}
	for(int len = 1; len <= n; ++len)
	{
		for(int l = 0; l + len <= n; ++l)
		{
			int r = l + len;
			if((b[r] ^ b[l]) == k) v.push_back(qujian(l + 1, r));
		}
	}
	sort(v.begin(), v.end());
	for(qujian &x : v)
	{
		if(res.empty()) res.push_back(x);
		else if(check(x)) res.push_back(x);
	}
	cout << res.size();
	return 0;
}
