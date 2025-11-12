#include<bits/stdc++.h>
using namespace std;
int n,q,m,ans;
string s[200010][2],t[2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	int x=0,y;
	for(int i=1;i<=q;i++)
	{
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size())
		{
			cout<<"0\n";
			continue;
		}
		ans=0;
		m=t[0].size();
		for(int j=1;j<=n;j++)
		{
			y=s[j][0].size();
			x=0;
			for(int k=0;k<m;k++)
			{
				if(t[0][k]==s[j][0][x]) x++;
				else x=0;
//				cout<<x<<" ";
				if(x==y)
				{
					bool tag=1;
//					cout<<k<<"\n";
					for(int u=0;u<k-y+1;u++)
						if(t[0][u]!=t[1][u])
						{
							tag=0;
							break;
						}
					if(!tag) continue;
					for(int u=k-y+1;u<=k;u++)
						if(t[1][u]!=s[j][1][u-k+y-1])
						{
							tag=0;
							break;
						}
					if(!tag) continue;
					for(int u=k+1;u<m;u++)
						if(t[0][u]!=t[1][u])
						{
							tag=0;
							break;
						}
					if(tag)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
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
