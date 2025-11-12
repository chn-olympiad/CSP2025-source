#include <bits/stdc++.h>
using namespace std;
struct eyz
{
	string s1 , s2;
} s[200020];
string f1(string a , string b , int l , int r , int i)
{
	string ls = "" , bzd = "";
	for (int k = l ; k < r ; k++)
	{
		ls += a[i];
		bzd += b[i];
	}
	if (ls == s[i].s1 && bzd == s[i].s2)
	{
		for (int k = l ; k < r ; k++)
		{
			a[i] = bzd[k - l];
		}
	}
	return a;
}
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> s[i].s1 >> s[i].s2;
	}
	string t1 , t2;
	while (q--)
	{
		int ans = 0;
		cin >> t1 >> t2;
		string s232 = t1;
		for (int l = 0 ; l <= t1.size() ; l++)
		{
			for (int r = l + 1 ; r <= t1.size() ; r++)
			{
				for (int i = 1 ; i <= n ; i++)
				{
//					if (s232[l : r] == s[i].s1 && t2[l : r] == s[i].s2) //为什么c++没有切片QwQ 
//					{
//						s232[l : r] = s2;
//					} // 真没招了 
					s232 = f1(s232 , t2 , l , r , i);
					if (s232 == t2) 
					{
						ans++;
						s232 = t1;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
