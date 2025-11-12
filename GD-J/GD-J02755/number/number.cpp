#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int num[N] , cnt;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i ++)
	{
		int x = s[i] - '0';
		if(0 <= x && x <= 9)
		{
			num[++ cnt] = x;
		}
	}
	sort(num + 1 , num + cnt + 1);
	for(int i = cnt ; i >= 1 ; i --)
	{
		cout << num[i];
	}
	return 0;
} 
