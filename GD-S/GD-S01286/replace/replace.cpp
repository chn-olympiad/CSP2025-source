#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][5];
int n, q;
string st, mo;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1; i <= q; i ++)
	{
		cin >> st >> mo;
		int ans = 0;
		for(int j = 1; j <= n; j++)
		{
			if((st.find(s[j][1]) <= st.length()) && (mo.find(s[j][2]) <= mo.length()) && st.find(s[j][1]) == mo.find(s[j][2]) && st.length() == mo.length())
			{
				int pos = st.find(s[j][1]);
				int loc = mo.find(s[j][2]);
//				cout << st.substr(0, pos) << " " << mo.substr(0, pos) << endl;
				if(st.substr(0, pos) != mo.substr(0, pos)) continue;
				pos += s[j][1].length();
				loc += s[j][2].length();
//				cout << st.substr(pos) << " " << mo.substr(loc) << endl;
				if(st.substr(pos) != mo.substr(loc)) continue;
				ans++;
//				cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
