#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[1000005];
string s2[1000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while (q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<s1[i].length()-t1.length()+1;j++)
			{
				int flag=0;
				for (int k=0;k<s1[i].length();k++)
				{
					if (t1[j+k]!=s1[i][j])
					{
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					string ss="";
					for (int k=0;k<j;k++)
						ss+=s1[i][k];
					for (int k=j;k<j+s1[i].length();k++)
						ss+=s2[i][k];
					for (int k=j+s1[i].length();k<t1.length();k++)
						ss+=s1[i][k];
					cout<<ss<<'\n';
					if (ss==t2)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

