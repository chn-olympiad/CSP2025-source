#include<bits/stdc++.h>
using namespace std;
int n, q;
string a[110000], b[110000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		string s, t;
		cin >> s >> t;
		for(int j=1;j<=n;j++)
		{
			string l, r;
			int ll = s.find(a[j]);
			int rr = t.find(b[j]);
			if(ll == rr&&ll <= s.size()&&ll >= 0) 
			{
				for(int k=0;k<s.size();k++)
				{
					if(k>=ll&&k<=ll+a[j].size()-1) l+= '0';
					else l += s[k];
				}
				for(int k=0;k<t.size();k++)
				{
					if(k>=ll&&k<=ll+b[j].size()-1) r+= '0';
					else r += t[k];
				}
				if(l==r) ans++;
			}	
		}	
		cout << ans << "\n";
	} 
	return 0;
} 
