#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
map<string,string>mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<s1.size();i++)
			for(int j=1;i+j-1<s1.size();j++)
				if(mp.count(s1.substr(i,j)))
				{
					string s=s1.substr(0,i)+mp[s1.substr(i,j)]+s1.substr(i+j);
					if(s==s2)cnt++;
				}
		cout<<cnt<<'\n';
	}
	return 0;
}
