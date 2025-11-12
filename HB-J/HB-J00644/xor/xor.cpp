/*
25-30 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int tr[MAXN<<2];
int a[MAXN];
int n,k;
int ans,cnt;
inline void pushup(int p)
{
	tr[p]=tr[(p<<1)]^tr[(p<<1|1)];
	return ;
}
inline void build(int l,int r,int p)
{
	if(l==r)
	{
		tr[p]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	pushup(p);
	return ;
}
inline int query_(int l,int r,int lg,int rg,int p)
{
	if(lg<=l&&r<=rg)
		return tr[p];
	int mid=(l+r)>>1;
	int ret=0;
	if(lg<=mid)
		ret=ret^query_(l,mid,lg,rg,(p<<1));
	if(rg>mid)
		ret=ret^query_(mid+1,r,lg,rg,(p<<1|1));
	return ret;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	build(1,n,1);
	for(int st=1;st<=n;++st)
	{
		for(int i=st;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				if(query_(1,n,i,j,1)==k)
				{
					cnt++;
					i=j+1;
				}
			}
		}
		ans=max(cnt,ans);
		cnt=0;
	}
	cout<<ans;
	return 0;
}