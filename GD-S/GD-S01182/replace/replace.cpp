#include <bits/stdc++.h>
using namespace std;
int n, q, l, r, len; 
string s1[200005], s2[200005]; 
string t1, t2; 
int bx1[200005], bx2[200005]; 
bool flag = true; 
int main()
{
	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q; 
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i]; 
	}
	while(q--)
	{
		cin >> t1 >> t2; 
		int sp1 = 0, sp2 = 0, dx1, dx2, ans = 0; 
		len = t1.size(); 
		l = -1, r = -1; 
		for(int i = 0; i < len; i++)
		{
			if(t1[i] != t2[i])
			{
				r = i; 
				if(l == -1)
					l = i; 
			}
		}
		if(l == -1 && r == -1)
		{
			cout << 0; 
			continue; 
		}
		string c1, c2; 
		for(int i = l; i <= r; i++)
		{
			c1.push_back(t1[i]); 
			c2.push_back(t2[i]); 
		}
		bool f = true; 
		for(int i = 1; i <= n; i++)
		{
			int x = s1[i].find(c1), y = s2[i].find(c2); 
			if(x == -1 || y == -1)
			{
				continue; 
			}
			if(t1.find(s1[i]) != -1 && t2.find(s2[i]) != -1)
			{
//				cout << s1[i] << " " << s2[i] << " " << t1 << " " << t2 << "\n"; 
				ans++; 
			}
		}
		cout << ans << "\n"; 
	}
	return 0;
}

