#include <bits/stdc++.h>
using namespace std;
int n, q;
struct node
{
	string s1, s2;
} s[200005];//可以将s1替换成s2 
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].s1 >> s[i].s2;
	}
	while(q--)
	{
		string a, b;
		int cnt = 0;
		cin >> a >> b;
		for(int i = 1; i <= n; i++)
		{
			int pos = 0;
			while(a.find(s[i].s1, pos)!=string::npos)
			{
				pos = a.find(s[i].s1, pos);
				string t = a;
				a.replace(pos, s[i].s1.size(), s[i].s2);
				if(a == b) cnt++;
				a = t;
				pos++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

