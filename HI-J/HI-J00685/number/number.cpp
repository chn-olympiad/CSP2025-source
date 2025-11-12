# include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	
	freopen("number.out", "w", stdout);
	
	string s;
	
	cin >> s;
	
	vector<int> result;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			result.push_back(s[i] - '0'); 
		}
	}
	
	sort(result.begin(), result.end(), cmp);
	
	for(auto i : result)
	{
		cout << i;
	}
	
	return 0;
}
