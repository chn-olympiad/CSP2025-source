#include<bits/stdc++.h>
using namespace std;
string s[200000+10][5];
int n,q,ans=0,b=-1,e=-1;
string qu1,qu2;
void dfs(string x,string y)
{
	for(int i=0; i<x.size(); i++)
	{
		if(qu1[i]!=qu2[i])
		{
			b=i;
			break;
		}
	}
	for(int i=0; i<x.size(); i++)
	{
		if(x[i]==y[i]&&i>b)
		{
			e=i;
			break;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(x==s[i][1]&&y==s[i][2])
		{
			ans++;
			continue;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(b==-1)
		{
			break;
		}
		for(int j=b; j<e; j++)
		{
			string o,p;
			o=s[i][1];
			p=s[i][2];
			if(x[j]!=o[j-b])
			{
				break;
			}
			else
			{
				if(y[j]!=p[j-b])
				{
					break;
				}
				else
				{
					if(j==e-1)
					{
						ans++;
					}
					continue;
				}
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>s[i][1];
		cin>>s[i][2];
	}
	for(int h=1; h<=q; h++)
	{
		ans=0;
		cin>>qu1>>qu2;
		dfs(qu1,qu2);
		cout<<ans<<endl;
	}
	return 0;
}


