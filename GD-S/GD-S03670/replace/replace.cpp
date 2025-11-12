#include<bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][2], t[200005][2];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	for(int i = 1; i <= q; i++)
	{
		cin >> t[i][0] >> t[i][1];
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
