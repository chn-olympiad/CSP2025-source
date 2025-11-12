#include <bits/stdc++.h>
using namespace std;

unordered_map < int, int > mp;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		mp[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		while (mp[i]) mp[i]--, cout << i;
	cout << '\n';
    return 0;
}
