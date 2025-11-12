#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n, q;
string s[N][3], t[N][3], ss[N][3];
int dp[5000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace1.in","r",stdin);
//	freopen("replace4.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i][1]>>s[i][2];
		ss[i][1]=s[i][1],ss[i][2]=s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			s[i][1]=ss[i][1],s[i][2]=ss[i][2];
			if(s[i][1].find(t[j][1])!=-1)
			{
				int tmp=s[i][1].find(t[j][1])+t[j][1].size()-1;
				string str=s[i][2].substr(tmp-t[j][1].size()+1,t[j][1].size());
				string str1=s[i][2].substr(tmp+1);
				string str2=s[i][2].substr(0,t[j][1].size());
				string astr=s[i][1].substr(tmp-t[j][1].size()+1,t[j][1].size());
				string astr1=s[i][1].substr(tmp+1);
				string astr2=s[i][1].substr(0,t[j][1].size());
				if(str==t[j][2])
				{
					s[i][1]=astr1+t[j][1]+astr2;
				}
		}
			if(s[i][1]==s[i][2])
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

