#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,a[500005],t,pos,ans,c[500005];
struct line
{
	int l,r;
}b[500005];
unordered_map<int,int> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	c[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		c[i]=c[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			b[++t].l=i;
			b[t].r=i;
		}
		else
		{
			int m=mp[k^c[i]];
			if(m!=0)
			{
				b[++t].l=m+1;
				b[t].r=i;
			}
		}
		mp[c[i]]=i;
	}
	for(int i=1;i<=t;i++)
	{
		if(b[i].l>pos)
		{
			ans++;
			pos=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
