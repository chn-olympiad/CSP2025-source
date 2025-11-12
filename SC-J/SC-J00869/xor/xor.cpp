#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000001],sum[1000001],dp[1000001],ma[1000001];
struct lrlr{int l,r;}lr[2000001];
bool cmp(lrlr x,lrlr y)
{
	return x.r<y.r || (x.r==y.r && x.l<y.l);
}
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k,ct=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		auto it=mp.find(sum[i]^k);
		if(it!=mp.end())
		{
			int tmp=it->second;
			lr[++ct].l=tmp+1,lr[ct].r=i;
		}
		mp[sum[i]]=i;
	}
	sort(lr+1,lr+ct+1,cmp);
	for(int i=1;i<=ct;i++)
	{
		int l=0,r=i;
		while(l<r)
		{
			int mid=l+(r-l)/2;
			if(lr[mid].r<lr[i].l) l=mid+1;
			else r=mid; 
		}
		r--;
		dp[i]=ma[r]+1;
		ma[i]=max(dp[i],ma[i-1]);
	}
	cout<<ma[ct];
	return 0;
}