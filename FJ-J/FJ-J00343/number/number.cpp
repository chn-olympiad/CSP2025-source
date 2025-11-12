#include <bits/stdc++.h>

using namespace std;

short a[(int) 1e6];
int index = 0;

int main()
{
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	
	for(unsigned int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[index] = s[i] - '0', index++;
		}
	}
	sort(a, a + index, less<int>());
	
	while(index--)
	{
		cout << a[index];
	}
	cout << endl;
	
	return 0;
}
