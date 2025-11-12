#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;
map<string,int> id;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		mp[x]++,mp[y]++;
		id[x]=i,id[y]=i;
	}
	if(q==1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		while(q--)
		{
			string s,t;
			cin>>s>>t;
			if(s.size()!=t.size())
			{
				cout<<"0\n";
				continue;
			}
			if(mp[s]==0&&mp[t]==0)
			{
				cout<<"0\n";
				continue;
			}
			if(id[s]==id[t])cout<<mp[s]+mp[t]<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
