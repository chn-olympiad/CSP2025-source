#include <bits/stdc++.h>
using namespace std;
int n; 
int a[100005][3] = {}, sum, s[3] = {}, v; 
struct st
{
	int d, s, s1, s2;
};
bool operator<(st a, st b)
{
	if (a.d == b.d)
	{
		if (a.s == b.s)
		{
			if (a.s1 == b.s1)
			{
				return a.s2 < b.s2;
			}
			else return a.s1 < b.s1;
		}
		else return a.s < b.s;
	}
	else return a.d < b.d;
}
map <st, int> fv;
int f(int depth)
{
	if (depth >= n)
	{
		return 0;
	}
	else if (fv[{depth, s[0], s[1], s[2]}]) return fv[{depth, s[0], s[1], s[2]}];
	
	int mxsum = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (s[i] == n / 2) continue;
		++s[i];
		//cout << string(depth, '\t') << "start" << endl;
		v = f(depth + 1);
		mxsum = max(v + a[depth][i], mxsum);
		//cout << '1' << string(depth, '\t') << s[0] << ',' << s[1] << ',' << s[2] << ',' << v << ','<< endl;
		--s[i];
	}
	fv[{depth, s[0], s[1], s[2]}] = mxsum;
	return mxsum;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while (t--)
	{
		s[0] = s[1] = s[2] = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		cout << f(0) << endl;
		fv.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

