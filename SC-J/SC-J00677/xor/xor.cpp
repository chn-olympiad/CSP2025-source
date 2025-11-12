#include <bits/stdc++.h>
using namespace std;

using ull=unsigned long long;

const int N=5e5+10;

struct NODE
{
	int l,r;
	bool operator< (const NODE &b) const
	{
		return r<b.r;
	}
};

int n,m=0,ans=0;
ull a[N],s[N],k;
map<ull,vector<int>> mp;
NODE b[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	sort(s,s+n+1);
	int tot=unique(s,s+n+1)-s;
	for(int i=1;i<=tot;i++)
	{
		sort(mp[s[i]].begin(),mp[s[i]].end());
	}
	for(int i=0;i<=tot;i++)
	{
		ull t=s[i]^k;
		for(int l=0,r=0;l<mp[s[i]].size();l++)
		{
			while(r<mp[t].size() && mp[s[i]][l]>=mp[t][r])
			{
				r++;
			}
			if(r>=mp[t].size())
			{
				break;
			}
			b[++m].l=min(mp[s[i]][l],mp[t][r])+1;
			b[m].r=max(mp[s[i]][l],mp[t][r]);
		}
	}
	sort(b+1,b+m+1);
	int last=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i].l<=last)
		{
			continue;
		}
		last=b[i].r;
		ans++;
	}
	cout<<ans;
	return 0;
}