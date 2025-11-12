#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string>> v;
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		v.push_back({s1,s2});	
	}
	while(q--)
	{
		int ans=0;
		cin>>s1>>s2;
		for(auto p:v)
		{
			if(p.first==s1)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;	
} 
