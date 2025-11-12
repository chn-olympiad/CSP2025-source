#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	vector <int> a;
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
		{
			a.push_back(tmp[i] - '0');
		}
	}
	
	sort (a.begin(), a.end(), greater<int>());
	
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	cout << endl;
	
	return 0;	
} 
