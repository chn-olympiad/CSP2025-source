#include <bits/stdc++.h>

using namespace std;

string s; vector <int> vec;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s; bool flag = false;
	
	for (int i = 0; i < s.length(); i ++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			vec.push_back(s[i] - '0');
			
			if (s[i] != '0') flag = true;
		}
	}
	
	if (flag == false)
	{
		cout << "0"; return 0;
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	for (int i = 0; i < vec.size(); i ++) cout << vec[i];
	
	return 0;
}
