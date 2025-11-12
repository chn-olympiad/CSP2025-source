#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[26];
int n,q;
mt19937 rnd(time(0));
pair<int,int> a[200010],b[200010];
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<26;i++)
	{
		c[i]=rnd();
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int su=0;
		for(auto i:s)
		{
			su+=c[i-'a'];
		}
		a[i].first=su;
		cin>>s;
		su=0;
		for(auto i:s)
		{
			su+=c[i-'a'];
		}
		a[i].second=su;
	}
	for(int i=1;i<=q;i++)
	{
		string s;
		cin>>s;
		int su=0;
		for(auto i:s)
		{
			su+=c[i-'a'];
		}
		b[i].first=su;
		cin>>s;
		su=0;
		for(auto i:s)
		{
			su+=c[i-'a'];
		}
		b[i].second=su;
	}
	for(int i=1;i<=q;i++)
	{
		int su=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j].first-b[i].first==a[j].second-b[i].second)
			su++;
		}
		cout<<su<<'\n';
	}
}
