#include <bits/stdc++.h>
using namespace std;
int n,q;
map <int,int> an;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int aj,bj;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='b')
			{
				aj=i;
				break;
			}
		}
		for(int i=0;i<b.size();i++)
		{
			if(b[i]=='b')
			{
				bj=i;
				break;
			}
		}
		an[aj-bj]++;
	}
	for(int i=1;i<=q;i++)
	{
		int aj,bj;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='b')
			{
				aj=i;
				break;
			}
		}
		for(int i=0;i<b.size();i++)
		{
			if(b[i]=='b')
			{
				bj=i;
				break;
			}
		}
		cout<<an[aj-bj]<<'\n';	
	}
	if(0)
	{
		cout<<"他妈的昨天晚上床上俩翘货阁我床上闹挺，几把的困死我了";
		int lm=1,rp=666;
		lm--;
		rp++;
	}
}
