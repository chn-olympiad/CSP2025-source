#include <bits/stdc++.h>
using namespace std;
string s;
int len, flag;
vector <int> ans;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			ans.push_back(s[i] - 48);
			if(s[i] != '0')
				flag = 1;
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for(auto i : ans)
		cout << i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
