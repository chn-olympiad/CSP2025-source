#include <bits/stdc++.h>
using namespace std;

int n, k; long long a[500005], s[500005];

struct node
{
	int beg, ed;
};

vector <node> v;

bool cmp(node a, node b)
{
	return a.ed < b.ed;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			if ((s[j] ^ s[i - 1]) == k) v.push_back({i, j});	
	sort(v.begin(), v.end(), cmp);
	int x = 0; long long tot = 1;
	for (int i = 1; i < (int) v.size(); i ++)
		if (v[i].beg > v[x].ed)
		{
			x = i;
			tot ++;
		}
	cout << tot << endl;
	return 0;
}
