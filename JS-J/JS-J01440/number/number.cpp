#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
string s;
vector<int> a;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rng((unsigned long long)(new char));
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(), a.end());
	for(int i = a.size()-1;i >= 0;i--)
	{
			cout << a[i];
	}
	return 0;
}
