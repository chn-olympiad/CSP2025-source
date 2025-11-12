#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	vector<char> vec;
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			vec.push_back(s[i]);
		}
	}
	sort(vec.begin(), vec.end());
	for(int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i];
	}
	return 0;
}
