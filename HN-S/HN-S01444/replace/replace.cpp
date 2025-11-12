#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[2*100005][3];
void solve()
{
    string t1,t2;
	int ans=0;
	cin>>t1>>t2;
	for(int i=1;i<=t1.length();i++)
	{
		for(int j=0;j<t1.length()-i+1;j++)
		{
			string ls="";
			for(int k=j;k<=j+i-1;k++)
			{
				ls+=t1[k];
			}
			for(int k=1;k<=n;k++)
			{
				if(ls==s[k][1])
				{
					string sy="";
					for(int m=0;m<j;m++)
					{
						sy+=t1[m];
					}
					sy+=s[k][2];
					for(int m=j+i;m<t1.length();m++)
					{
						sy+=t1[m];
					}
					if(sy==t2)
					{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
