#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;

bool cmp(char a, char b)
{
	return a > b;
}
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	vector<char> num;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num.push_back(s[i]);
		}
	}
	sort(num.begin(), num.end(), cmp);
	string str = "";
	for(int i = 0;i < num.size();i++)
	{
		str += num[i];
	}
	cout << str;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
