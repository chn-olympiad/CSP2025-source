#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 15;
string s;
ll num[N]; 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	s = '#' + s;
	for(ll i = 1; i <= s.size(); i++)
	{
		char c = s[i];
		if(c >= '0' && c <= '9')
		{
			num[c - '0']++;
		}
	}
	for(ll i = 9; i >= 0; i--)
	{
		while(num[i] > 0)
		{
			cout << i;
			num[i]--;
		}
	}
	return 0;	
} 
