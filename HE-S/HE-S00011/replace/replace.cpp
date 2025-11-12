#include <bits/stdc++.h>
using namespace std;
int n,q;
struct P
{
	string a;
	string b;
}s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	while (q--)
	{
		string x,y;
		cin>>x>>y;
		if (x.size()!=y.size())
		{
			cout<<0<<endl;
		}
		else
		{
			int sum=0;
			for (int i=0;i<x.size();i++)
			{
				if (x[i]!=y[i])
				{
					sum++;
				}
			}
			if (sum<3)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
