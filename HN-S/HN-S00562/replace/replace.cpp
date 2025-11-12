#include<bits/stdc++.h>
using namespace std;
int n,Q;
string s1,s2;
unordered_map<string,unordered_set<string> > mp;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp[s1].insert(s2);
	}
	while(Q--)
	{
		cin>>s1>>s2;
		int l,r,len=s1.size();
		long long ans=0;
		for(l=0;l<len;l++)
		{
			if(s1[l]!=s2[l])break;
		}
		for(r=len-1;r>=0;r--)
		{
			if(s1[r]!=s2[r])break;
		}
		for(int i=l;i>=0;i--)
		{
			string t1 = s1.substr(i,r-i);
			string t2 = s2.substr(i,r-i);
			for(int j=r;j<len;j++)
			{
				t1+=s1[j];
				t2+=s2[j];
				if(mp[t1].count(t2))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
