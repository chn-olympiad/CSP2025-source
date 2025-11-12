#include <bits/stdc++.h>
using namespace std;
map<pair<string, string>, int> mm;
const int N = 2e5+10;
int n, q, len;
string s1[N], s2[N], t1, t2;
int ff(int aa)
{
	if(aa == len)
		return 1;
	string ss = "", tt = "";
	int sum = 0;
	if(t1[aa] == t2[aa])
		sum = ff(aa+1);
	for(int i = aa; i < len; i++)
	{
		ss = ss+t1[i];
		tt = tt+t2[i];
		if(mm[{ss, tt}])
		{
			mm[{ss, tt}]--;
			sum += (mm[{ss, tt}]+1)*ff(i+1);
			mm[{ss, tt}]++;
		}
	}
	return sum;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
		mm[{s1[i], s2[i]}]++;
	}
	while(q--)
	{
		cin >> t1 >> t2;
		len = t1.size();
		if(t2.size() != len)
		{
			cout << 0 << '\n';
			continue;
		}
		cout << ff(0) << '\n';
	}
	return 0;
}
