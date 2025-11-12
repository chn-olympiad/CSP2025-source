#include<bits/stdc++.h>
using namespace std;
int a[500005],suff[500005],cnt;
unordered_map<int,unordered_set<int> >mp;
struct P
{
	int l,r;
}p[1000005];
bool cmp(P a,P b)
{
	if(a.r!=b.r)
		return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	mp[0].insert(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suff[i]=suff[i-1]^a[i];
		for(auto e:mp[m^suff[i]])
			p[++cnt]={e+1,i};
		mp[suff[i]].insert(i);
	}
	sort(p+1,p+cnt+1,cmp);
	int lst=-1,ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(p[i].l>lst)
		{
			lst=p[i].r;
			ans++;
		}
	}
	cout<<ans;
}
