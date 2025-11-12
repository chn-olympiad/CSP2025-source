# include <bits/stdc++.h>
using namespace std;

vector <int> a;

void num(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			a.push_back(str[i] - 48);
		}
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string str;
	cin >> str;
	
	num(str);
	
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++) 
		{
			if (a[i] < a[j]) swap(a[i], a[j]);
		}
	}
	
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	
	return 0;
}