#include<bits/stdc++.h>
using namespace std;
string s[200005][3],t[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size())
			cout<<"0";
		else
		{
			for(int ii=0;ii<t[i][1].size();ii++)
			{
				for(int j=1;j<=n;j++)
				{
					if(t[i][1].size()-ii>=s[j][1].size())
					{
						bool bol=true;
						for(int w=0;w<s[j][1].size();w++)
							if(t[i][1][ii+w]!=s[j][1][w])
								bol=false;
						if(bol)
						{
							string newstr="";
							for(int e=0;e<ii;e++)
								newstr+=t[i][1][e];
							newstr+=s[j][2];
							for(int e=ii+s[j][2].size();e<t[i][1].size();e++)
								newstr+=t[i][1][e];
							if(newstr==t[i][2])
								ans++;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
