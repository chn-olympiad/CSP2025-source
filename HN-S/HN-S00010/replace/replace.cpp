#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int n, q;
string s[N][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	while(q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		int tot = 0;
		for(int i = 1; i <= n; i++)
		{
			int lst = t1.find(s[i][0]);
			while(lst != -1)
			{
				string res = t1.substr(0, lst) + s[i][1] + t1.substr(lst + s[i][0].size());
				if(res == t2) tot++;
				lst = t1.find(s[i][0], lst + s[i][0].size());
			}
		}
		cout << tot << "\n";
	}
	return 0;
}

