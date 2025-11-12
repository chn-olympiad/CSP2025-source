#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
const int N=2e5+5;
int a[N],b[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='b')
			{
				l=i;
				break;
			}
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='b')
			{
				r=i;
				break;
			}
		a[i]=r-l;
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='b')
			{
				l=i;
				break;
			}
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='b')
			{
				r=i;
				break;
			}
		b[i]=r-l;
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
			if(b[i]-a[j]==0)
				ans++;
		cout<<ans<<'\n';
	}
//	while(m--)
//	{
//		cout<<0<<'\n';
//	}
	return 0;
}

