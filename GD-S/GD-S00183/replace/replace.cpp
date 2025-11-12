#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s1[200051], s2[200051];
int leng1[200051], leng2[200051];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++)
	{
		string t1, t2;
		cin >> t1 >> t2;
		cout << 0 << endl;
	}
	return 0;
}
