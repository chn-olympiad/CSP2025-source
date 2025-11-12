#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200001][3],t[200001][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int c=1;c<=n;c++)
	{
		cin>>s[c][1]>>s[c][2];
	}
	for(int c=1;c<=q;c++)
	{
		cin>>t[c][1]>>t[c][2];
		int l=t[c][1].size(),r=1;
		ans=0;
		for(int i=0;i<t[c][1].size();i++)
		{
			if(t[c][1][i]!=t[c][2][i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(t[c][1].find(s[i][1])==-1||t[c][2].find(s[i][2])==-1) continue;
			if(r-l+1>s[i][1].size()) continue;
			int x=t[c][1].find(s[i][1]),y=t[c][2].find(s[i][2]);
			if(x>l||x+s[i][1].size()<r||y>l||y+s[i][1].size()<r) continue;
			for(int j=0;j<t[c][1].size();j++)
			{
				if(t[c][1].substr(j,s[i][1].size())==s[i][1]&&l>=j&&r<=j+s[i][1].size()-1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
