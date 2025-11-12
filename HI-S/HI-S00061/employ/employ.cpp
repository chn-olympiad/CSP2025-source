#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,c[505],a[505],b[505],ans;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
		b[i]=i;
	}
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')f=false;
	}
	if(m==n)
	{
		if(f==false)
		{
			cout<<0;
			return 0;
		}
	}
	int t=0;
	next_permutation(a+1,a+n+1);
	while(1)
	{
		f=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=b[i])f=false;
		}
		if(f)break;
		next_permutation(a+1,a+n+1);
		t++;
		t=t%p;
	}
	while(t--)
	{
		int lu=0,fa=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				fa++;
			}
			else
			{
				if(fa>=c[a[i]])
				{
					fa++;
				}
				else
				{
					lu++;
				}
			}
		}
		if(lu>=m)ans++;
		next_permutation(a+1,a+n+1);
		ans=ans%p;
	}
	cout<<ans;
} 
