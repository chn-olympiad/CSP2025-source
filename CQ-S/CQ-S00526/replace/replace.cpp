#include <bits/stdc++.h>
using namespace std;
#define ll long long
namespace Jayfeather
{
	int n,m;
	string s,t;
	map<pair<string,string>,vector<pair<string,string> > > p;
	signed main()
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>s>>t;
			int l,r;
			string ls="",rs="";
			for(int j=0;j<s.size();j++)
			{
				if(s[j]!=t[j])
				{
					l=j;
					break ;
				}
				ls=ls+s[j];
			}
			for(int j=s.size()-1;j>=0;j--)
			{
				if(s[j]!=t[j])
				{
					r=j;
					break ;
				}
				rs=s[j]+rs;
			}
			string ps="",qs="";
			for(int j=l;j<=r;j++)
			{
				ps+=s[j];
				qs+=t[j];
			}
			p[{ps,qs}].push_back({ls,rs});
		}
		for(int i=1;i<=m;i++)
		{
			cin>>s>>t;
			int l,r;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]!=t[j])
				{
					l=j;
					break ;
				}
			}
			for(int j=s.size()-1;j>=0;j--)
			{
				if(s[j]!=t[j])
				{
					r=j;
					break ;
				}
			}
			string ps="",qs="";
			for(int j=l;j<=r;j++)
			{
				ps+=s[j];
				qs+=t[j];
			}
			int cnt=0;
			for(pair<string,string> j:p[{ps,qs}])
			{
				string ls="",rs="";
				for(int k=l-1,l=0;l<j.first.size();k--,l++)
				{
					ls=s[k]+ls;
				}
				for(int k=r+1,l=0;l<j.second.size();k++,l++)
				{
					rs=rs+s[k];
				}
//				cout<<ls<<" "<<rs<<'\n';
				if(ls==j.first&&rs==j.second) cnt++;
			}
			cout<<cnt<<'\n';
		}
		return 0;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return Jayfeather::main();
} 
/*
time: 4.404/1s
mem: 12.40/2048MB
*/
