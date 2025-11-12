#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
string s;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	vector<char> v;
	for(char c : s) if(c >= '0' && c <= '9') v.push_back(c);
	sort(begin(v), end(v), greater<char>());
	for(char i : v) cout << i;
	return 0;
}