#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int>m;
int n,q;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string a1="",b1="";
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			m[make_pair(a,b)]++;
		}
		else
		{
			a1="";b1="";
			for(int i=0;i<a.size();i++)
			{
				if(a[i]!=b[i])
				{
					a1+=a[i];
					b1+=b[i];
				}
			}
			m[make_pair(a1,b1)]++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<m[make_pair(a,b)]<<endl;
		}
		else
		{
			a1="";b1="";
			for(int i=0;i<a.size();i++)
			{
				if(a[i]!=b[i])
				{
					a1+=a[i];
					b1+=b[i];
				}
			}
			cout<<m[make_pair(a1,b1)]<<endl;
		}
	}
	return 0;
}
