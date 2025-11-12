#include <bits/stdc++.h>
using namespace std;
string s[200010][2],s1,s2;
int pos[200010][2];
int q,n,p1,p2,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<s[i][j].size();k++)
				if(s[i][j][k]=='b')
				{
				
					pos[i][j]=k;
					break;
				}
		}
	while(q--)
	{
		ans=0;
		cin>>s1>>s2;
	
		for(int i=0;i<s1.size();i++)
			if(s1[i]=='b')
			{
				p1=i;
			}
		for(int i=0;i<s2.size();i++)
			if(s2[i]=='b')
			{
				p2=i;
			}
		for(int i=1;i<=n;i++)
		{
			int si0q=s[i][0].size() - pos[i][0];
			int si0h=s[i][0].size()-1-si0q;
			int s10q=s1.size()-p1;
			int s10h=s1.size()-1-s10q;
			if(s10q>=si0q&&s10h>=si0h)
			{
				string ns;
				for(int i=1;i<=s10q-si0q;i++)
				ns+='a';
				ns+=s[i][1];
				for(int i=1;i<=s10h-si0h;i++)ns+='a';
				if(ns==s2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
