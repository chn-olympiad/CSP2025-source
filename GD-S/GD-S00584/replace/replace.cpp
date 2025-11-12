#include <bits/stdc++.h>
using namespace std;

struct v
{
	string s1,s2;
};

v a[200005];
int n,q;
int ans = 0;
string target;

int dfs(string s,int k)
{
	int f = 0;
	int sl;
	string l,r;
	//cout << s << endl;
	if (s == target)
	{
		ans++;
		return 0;
	}
	for(int j = 1;j <= n;j++)
	{
	    sl = a[j].s1.length();
	    for(int i = 1;i <= k - sl;i++)
	    {
	    	//cout << s.substr(i,i + sl - 2) << endl;
	    	if (s.substr(i,i + sl - 2) == a[j].s1)
	    	{
	    		l = s.substr(1,i - 1);
	    		r = s.substr(i + sl,k + 1);
	    		dfs(l + a[j].s2 + r,k);
	    		f = 1;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].s1 >> a[i].s2;
	}
	string s;
	for(int i = 1;i <= q;i++)
	{
		//ans = 0;
		cin >> s >> target;
		//dfs(" " + s,s.length());
		cout << 0 << endl;
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
*/
/*
2
0
*/

