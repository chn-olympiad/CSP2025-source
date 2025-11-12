#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//typedef long long LL;
const int MAXN = 200005;
string u[MAXN];
string v[MAXN];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> u[i] >> v[i];
	
	while (q--)
	{
		string q_1, q_2; cin >> q_1 >> q_2;
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int len_u = u[i].size();
			int len_v = v[i].size();
			
			int t_ans = 0;
			for (int j = 0; j < min(q_1.size(), q_2.size()); j++)
			{
				string x = q_1.substr(j, len_u);
				string y = q_2.substr(j, len_v);
				
//				cout << x << ' ' << y << endl;
				
				if (x == u[i] && y == v[i]) t_ans++;
			}
			
			if (t_ans == min(q_1.size(), q_2.size()) - len_u + 1 && min(q_1.size(), q_2.size()) != len_u) t_ans = 0;
			ans += t_ans;
		}
		
		cout << ans << endl;
	}	

	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/ 
