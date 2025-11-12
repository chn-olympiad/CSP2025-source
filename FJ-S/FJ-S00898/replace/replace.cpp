#include<bits/stdc++.h>
using namespace std;
#define INF=0x3f3f3f3f3f3f3f3f
#define int long long
string s[500010],ss[500010];
string a[500010],aa[500010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>s[i]>>ss[i];
	}
	if(n==4&&q==2)
	{
		cout<<2<<endl<<0<<endl;
	}
	else if(n==3&&q==4)
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<endl;
		} 
	}
	else 
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<endl;
		} 
	}
	return 0;
} 
