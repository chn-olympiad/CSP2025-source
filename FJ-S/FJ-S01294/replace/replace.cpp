#include<bits/stdc++.h>
using namespace std;
int n,q;
map <string,string> mp;
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	//ovo qwq awa
	//我要上迷惑行为大赏 
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
		int ans=0;
		cin>>s1>>s2;
		for(int mid1=0;mid1<s1.size();mid1++)
			for(int mid2=mid1;mid2<=s1.size();mid2++)
			{
				string x=s1.substr(0,mid1),
				y=s1.substr(mid1,mid2-mid1),
				z=s1.substr(mid2);
				if(mp.count(y))
				{
					string res=x+mp[y]+z;
					if(res==s2)ans++;
				}
			}
		cout<<ans<<'\n';
	}
}
