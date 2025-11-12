#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
map<string,string> mp;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		string a,b;cin>>a>>b;
		mp[a]=b;
	}
	
	while(q--)
	{
		string a,b;cin>>a>>b;
		int m=a.size();
		int l=0,r=m-1,cnt=0;
		
		while(a[l]==b[l]) ++l;
		while(a[r]==b[r]) --r;
		
		for(int i=0;i<=l;i++)
			for(int j=m-1;j>=r;j--)
			{
				string t=a.substr(i,j-i+1);
				if(mp[t]==b.substr(i,j-i+1))
					++cnt;
			}
		cout<<cnt<<'\n';	
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
