#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
string s[200010][2],t[200010][2];
vector<int>p[200010][2];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++)
	{
		p[i][0].pb(-1);
		for(int j=1;j<s[i][0].size();j++)
		{
			int k=p[i][0][j-1];
			while(k!=-1&&s[k+1]!=s[j])k=p[i][0][k];
			if(k==-1&&s[k+1]!=s[j])p[i][0].pb(-1);
			else p[i][0].pb(k+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		p[i][1].pb(-1);
		for(int j=1;j<s[i][1].size();j++)
		{
			int k=p[i][1][j-1];
			while(k!=-1&&s[k+1]!=s[j])k=p[i][1][k];
			if(k==-1&&s[k+1]!=s[j])p[i][1].pb(-1);
			else p[i][1].pb(k+1);
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(t[i][0].size()!=t[i][1].size()){cout<<0<<endl;continue;}
		int bg1=-1,bg2=LONG_LONG_MAX,ans=0;
		for(int j=t[i][0].size()-1;j>=0;j--)
			if(t[i][0][j]!=t[i][1][j])
			{
				bg1=j;
				break;
			}
		for(int j=0;j<t[i][0].size();j++)
			if(t[i][0][j]!=t[i][1][j])
			{
				bg2=j;
				break;
			}
		for(int j=1;j<=n;j++)
		{
			int d1=-1,d2=-1;
			for(int k=0;k<t[i][0].size();k++)
			{
				while(d1!=-1&&s[j][0][d1+1]!=t[i][0][k])d1=p[j][0][d1];
				if(s[j][0][d1+1]==t[i][0][k])d1++;
				while(d2!=-1&&s[j][1][d2+1]!=t[i][1][k])d2=p[j][1][d2];
				if(s[j][1][d2+1]==t[i][1][k])d2++;
				if(d1==s[j][0].size()-1&&d2==s[j][1].size()-1&&k>=bg1&&k-s[j][0].size()+1<=bg2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2 1
a a
b b
a a
*/
