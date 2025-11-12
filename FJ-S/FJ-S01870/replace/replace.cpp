#include <bits/stdc++.h>
using namespace std;
int n, q;
vector <string> s[2];
string s1, s2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b ;
		s[0].push_back(a);
		s[1].push_back(b);
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> s1 >> s2;
	}
	
	
	
	return 0;
}
