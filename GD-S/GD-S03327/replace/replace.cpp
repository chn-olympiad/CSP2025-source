#include <bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005];
int zl[200005],zr[200005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		int l = -1,r = 0;
		for(int j = 0;j < s1[i].size();j++)
		{
			if(s1[i][j] != s2[i][j])
			{
				if(l == -1) l = j;
				r = j; 
			}
		}
		zl[i] = l;
		zr[i] = r;
	}
	for(int i = 1;i <= q;i++)
	{
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int l = -1,r = 0;
		for(int j = 0;j < t1.size();j++)
		{
			if(t1[j] != t2[j])
			{
				if(l == -1) l = j;
				r = j; 
			}
		}
		int ans = 0;
		for(int j = 1;j <= n;j++)
		{
			if(s1[j].size() < (r - l + 1) || s1[j].size() > t1.size() || (zr[j] - zl[j]) != (r - l) || (l - zl[j]) < 0 || (l - zl[j] + s1[j].size()) > t1.size()) continue;
			if(t1.substr(l - zl[j],s1[j].size()) == s1[j] && t2.substr(l - zl[j],s2[j].size()) == s2[j])
			{
				ans++;
		 	} 
		}
		cout << ans << endl;
	}
	return 0;
} 
