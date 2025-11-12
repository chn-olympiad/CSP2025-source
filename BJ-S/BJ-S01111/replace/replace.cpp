#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NR = 2e5+10;
string a[NR], b[NR], c[NR], d[NR];
int v[NR], sz;

bool cpr(string x, string y)
{
	for (int i = 0; i < max(x.size(), y.size()); i++)
		if (i >= x.size()) return 1;
		else if (i >= y.size()) return 0;
		else if (x[i] != y[i]) return x[i] < y[i];
	return 0;
}

bool cmp(int i, int j)
{
	if (a[i] != a[j]) return cpr(a[i], a[j]);
	if (b[i] != b[j]) return cpr(b[i], b[j]);
	if (c[i] != c[j]) return cpr(c[i], c[j]);
	return cpr(d[i], d[j]);
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s, t;
		cin >> s >> t;
		int l = 0;
		while (l < s.size() && s[l] == t[l]) l++;
		int r = s.size() - 1;
		while (r >= 0 && s[r] == t[r]) r--;
		if (l <= r)
		{
			a[i] = s.substr(l, r - l + 1);
			b[i] = t.substr(l, r - l + 1);
			a[i] += "#";
			b[i] += "#";
			c[i] = s.substr(0, l);
			reverse(c[i].begin(), c[i].end());
			if (r + 1 < s.size()) d[i] = s.substr(r + 1);
			//c[i] += "#";
			//d[i] += "#";
			v[++sz] = i;
		}
	}
	sort(v + 1, v + sz + 1, cmp);
	//for (int i = 1; i <= sz; i++)
	//	cout << a[v[i]] << ' ' << b[v[i]] << ' ' << c[v[i]] << ' ' << d[v[i]] << endl;
	while (q--)
	{
		string s, t;
		cin >> s >> t;
		int l = 0;
		while (l < s.size() && s[l] == t[l]) l++;
		int r = s.size() - 1;
		while (r >= 0 && s[r] == t[r]) r--;
		string A = s.substr(l, r - l + 1);
		string B = t.substr(l, r - l + 1);
		A += "#", B += "#";
		string C = s.substr(0, l);
		reverse(C.begin(), C.end());
		string D = s.substr(r + 1);
		//C += "#", D += "#";
		//cout << A << ' ' << B << ' ' << C << ' ' << D << endl;
		int L = 1, R = sz;
		for (int i = 0; i < A.size(); i++)
		{
			if (L > R) break;
			int l = L, r = R, ll = R + 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (a[v[mid]][i] >= A[i])
					ll = mid, r = mid - 1;
				else l = mid + 1;
			}
			int rr = L - 1;
			l = L, r = R;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (a[v[mid]][i] <= A[i])
					rr = mid, l = mid + 1;
				else r = mid - 1;
			}
			L = ll, R = rr;
		}
		for (int i = 0; i < B.size(); i++)
		{
			if (L > R) break;
			int l = L, r = R, ll = R + 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (b[v[mid]][i] >= B[i])
					ll = mid, r = mid - 1;
				else l = mid + 1;
			}
			int rr = L - 1;
			l = L, r = R;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (b[v[mid]][i] <= B[i])
					rr = mid, l = mid + 1;
				else r = mid - 1;
			}
			L = ll, R = rr;
		}
		int ans = 0;
		if (n <= 1e6)
		{
			for (int i = L; i <= R; i++)
			{
				if (c[v[i]].size() > C.size()) continue;
				if (d[v[i]].size() > D.size()) continue;
				if (C.substr(0, c[v[i]].size()) != c[v[i]]) continue;
				if (D.substr(0, d[v[i]].size()) != d[v[i]]) continue;
				ans++;
			}
			cout << ans << endl;
		}
		else
		{
			for (int i = 0; i < C.size(); i++)
			{
				if (L > R) break;
				int l = L, r = R, ls = L - 1;
				while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (c[v[mid]].size() <= i)
						ls = mid, l = mid + 1;
					else r = mid - 1;
				}
				
				if (ls >= L)
				{
					int lll = L, rrr = ls, rs = L - 1;
					while (lll <= rrr)
					{
						int mid = (lll + rrr) >> 1;
						if (d[v[mid]].size() <= D.size())
							rs = mid, lll = mid + 1;
						else rrr = mid - 1;
					}
					ans += rs - L + 1;
				}
				
				l = L = ls + 1, r = R;
				int ll = R + 1;
				while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (c[v[mid]][i] >= C[i])
						ll = mid, r = mid - 1;
					else l = mid + 1;
				}
				int rr = L - 1;
				l = L, r = R;
				while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (c[v[mid]][i] <= C[i])
						rr = mid, l = mid + 1;
					else r = mid - 1;
				}
				L = ll, R = rr;
			}
			cout << ans << endl;
		}
	}
	return 0;
}