#include<bits/stdc++.h>
using namespace std;
string s[200001][2];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for (int k=1;k<=q;k++)
	{
		string t1, t2;
		cin>>t1>>t2;
		int ans=0;
		for (int l=1;l<=n;l++)
		{
			if (int(t2.length())>int(s[l][0].length()))
			{
				for (int i=0;i<=int(t2.length()-s[l][0].length());i++)
				{
					string tt=t1;
					int yes=1;
					for (int j=0;j<int(s[l][0].length());j++)
					{
						if (tt[i+j]==s[l][0][j])
						{
							tt[i+j]=s[l][1][j];
						}
						else 
						{
							yes=0;
						}
					}
					if (yes&&tt==t2)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
