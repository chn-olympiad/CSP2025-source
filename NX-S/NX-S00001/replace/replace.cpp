#include <bits/stdc++.h>
using namespace std;

struct pl
{
	string p1,p2;
};
pl s[1000010];
bool f(string x,string y)
{
	if(x==y)
	    return true;
	if(x.size()>y.size())
	{
		int z=x.size();
		for(int i=0;i<z;i++)
		{
			if(y[0]==x[i])
			{
				string q;
				for(int j=i;j<z;j++)
					q=q+x[j];
				if(y==q)
					return true;
				else
				    return false;
			}
		}
	}
	else
	{
		int z=y.size();
		for(int i=0;i<z;i++)
		{
			if(x[0]==y[i])
			{
				string q;
				for(int j=i;j<z;j++)
					q=q+y[j];
				if(x==q)
					return true;
				else
				    return false;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,c=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].p1>>s[i].p2;
	}
	for(int i=1;i<=q;i++)
	{
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			if(f(x,s[i].p2)||f(y,s[i].p1))
			{
				c++;
			}
		    if(x==s[i].p2)
				c++;
		    if(y==s[i].p1)
				c++;
		}
		cout<<c<<endl;
	}
	
	
	return 0;
}
