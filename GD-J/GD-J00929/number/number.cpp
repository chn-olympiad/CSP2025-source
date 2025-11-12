#include<bits/stdc++.h>
#define LL long long
using namespace std;

string s, a;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(char c : s)
	{
		if('0' <= c and c <= '9')
			a += c;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	cout << a;
	return 0;
 } 
