#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;

int n, m;
string s[MAXN][2], t[MAXN][2];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++) cin>>t[i][0]>>t[i][1];
	for(int k=1;k<=m;k++)
	{
//		cerr<<"k="<<k<<'\n';
		int ans = 0;
		int lt = t[k][0].size();
		int p[MAXN];
		p[0] = (t[k][0][0] == t[k][1][0]);
		for(int i=1;i<lt;i++) p[i] = p[i-1] + (t[k][0][i] == t[k][1][i]);
		for(int i=1;i<=n;i++)
		{
			int ls = s[i][0].size();
			int l = t[k][0].size()-ls+1;
			for(int j=0;j<l;j++)
			{
				bool f = (p[lt-1] - p[j+ls-1] == lt-j-ls);
				if(j) f &= (p[j-1] == j);
				if(!f) continue;
				int tot = 0;
				while(t[k][0][j+tot] == s[i][0][tot] && t[k][1][j+tot] == s[i][1][tot] && tot < ls) tot++;
				if(tot == ls) ans++;
			}
		}
		cout<<ans<<'\n';
//		cerr<<ans<<'\n';
	}
	return 0;
}
/*

5 3
a b
aa bb
abc acd
ef fe
xax xbx
aa bb
bcb bcd
xax xbx
*/
