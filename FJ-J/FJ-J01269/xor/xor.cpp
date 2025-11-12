#include<bits/stdc++.h>
#define N 500500
using namespace std;
map<int,pair<bool,int>>mp;
int n,k,a[N],l[N],ans,f[N],r[N],sum,now;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	mp[0].first=1;mp[0].second=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	  now^=a[i];
	  if(a[i]==k) l[i]=i;
	  else if(mp[now^k].first) l[i]=mp[now^k].second+1;
	  mp[now].first=1;mp[now].second=i;
	}
	for(int i=1;i<=n;i++)
	  {
	    f[i]=f[i-1];
		if(l[i]!=0) f[i]=max(f[i],f[l[i]-1]+1);
	  }
	cout<<f[n];
	return 0;
}
