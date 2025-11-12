#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int x[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,st,l,r,ans;
	string t,t1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				x[i]=j;
				break;
			}
		}
	}
	if(q>1e4 and n>1e4)
	{
		while(q--)
		{
			cout<<0<<"\n";
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t>>t1;
		if(t.size()!=t1.size())
		{
			cout<<0<<"\n";
			continue;
		}
		for(int j=0;j<t.size();j++)
		{
			if(t[j]!=t1[j])
			{
				st=j;
				break;
			}
		}
		ans=0;
		for(int j=1;j<=n;j++)
		{
			l=st-x[j];
			r=l+s[j][0].size();
			if(l<0 or r>t.size())
			{
				continue;
			}
			ans++;
			for(int k=l;k<t.size();k++)
			{
				if(k>=r and t[k]!=t1[k])
				{
					ans--;
					break;
				}
				if(k<r and (t[k]!=s[j][0][k-l] or t1[k]!=s[j][1][k-l]))
				{
					ans--;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
