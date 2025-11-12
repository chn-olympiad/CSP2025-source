#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,c;
string s1,s2;
map<int,int> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int m=s1.size(),v=0;
		for(int j=0;j<m;j++)	v=(v*131313+114*s1[j]+511*s2[j])%1000000009;
		mp[v]++;
	}
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		int m=s1.size(),pos,ans=0;
		for(int i=m;i>=1;i--)
			if(s1[i-1]!=s2[i-1])
			{
				pos=i;
				break;
			}
		for(int l=1;l<=m;l++)
		{
			for(int r=l,v=0;r<=m;r++)
			{
				v=(v*131313+114*s1[r-1]+511*s2[r-1])%1000000009;
				if(r>=pos)	ans+=mp[v];
			}
			if(s1[l-1]!=s2[l-1])	break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
