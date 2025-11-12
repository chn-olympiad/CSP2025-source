#include<bits/stdc++.h>
using namespace std;
int n,q,ans,s;
string str,str1,str2;
char c[1001][2001],d[1001][2001],e[1001];
void solve1()
{
	while(q--)
	{
		cin>>str1;
		cin>>str2;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int l=0;l<str1.size();l++)
			{
				if((l+e[i]-1)>=str1.size())
				{
					break;
				}
				bool flag=1;
				for(int j=l;j<=l+e[i]-1;j++)
				{
					if(str1[j]!=c[i][j-l])
					{
						flag=0;
					}
				}
				if(flag)
				{
					/*for(int j=0;j<e[i];j++)
					{
						cout<<c[i][j];
					}*/
					string nstr=str1;
					for(int j=l;j<=l+e[i]-1;j++)
					{
						nstr[j]=d[i][j-l];
					}
					//cout<<nstr;
					flag=1;
					for(int j=0;j<nstr.size();j++)
					{
						if(nstr[j]!=str2[j])
						{
							flag=0;
						}
					}
					if(flag)
					{
						ans++;
					}
					//cout<<ans<<"\n";
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(int j=0;j<str.size();j++)
		{
			c[i][j]=str[j];
		}
		cin>>str;
		for(int j=0;j<str.size();j++)
		{
			d[i][j]=str[j];
		}
		e[i]=str.size();
	}
	solve1();
	return 0;
}
