#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	int num[20]{0};
	for(int i=0; i<s.length(); i++)
	{
		int tmp = s[i] - '0';
		if(tmp >= 0 && tmp <= 9) num[tmp]++; 
	}
	for(int i=9; i>=0; i--)
	{
		while(num[i] > 0)
		{
			cout << i; 
			num[i]--;
		}
	}
	cout << endl;
	return 0;
}