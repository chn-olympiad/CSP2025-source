#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct str
{
	string s1,s2;
}a[201010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	while(m--)
	{
		int ans=0;
		string x,y;
		cin>>x>>y;
		int xl=x.size(),yl=y.size();
		for(int i=0;i<xl;i++)
		{
			for(int j=i;j<xl;j++)
			{
				string h="";
				for(int k=i;k<=j;k++)
				{
					h+=x[k];
				}
//				cout<<h<<"\n";
				for(int k=1;k<=n;k++)
				{
					if(h==a[k].s1)
					{
//						cout<<a[k].s2<<"\n";
						int p=0;
						for(int u=0;u<xl;u++)
						{
							if(u<=j&&u>=i)
							{
								if(a[k].s2[u-i]!=y[u])
								{
									p=1;
									break;
								}
							}
							else
							{
								if(x[u]!=y[u])
								{
									p=1;
									break;
								}
							}
						}
						if(p==0)
						{
//							cout<<"OK\n";
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
