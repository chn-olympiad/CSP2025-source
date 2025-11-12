#include<bits/stdc++.h>
using namespace std;
struct data
{
	int l,r;
	friend bool operator < (data a,data b)
	{
		if(a.r!=b.r) return a.r<b.r;
		return a.l>b.l;
	}
}q[500005];
int n,k,s,ans,cnt,r,a[500005],b[500005],c[500005];
bool f[500005];
set<int> pos[1<<20];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i],pos[b[i]].insert(i);
		c[i]=c[i-1];
		if(a[i]==k)
		{
			ans++,c[i]++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		int need=k^b[i-1];
		int p=*pos[need].upper_bound(i);
		if(p>i&&c[p]-c[i-1]==0) q[++cnt]={i,p};
	}
	sort(q+1,q+1+cnt);
	for(int i=1;i<=cnt;i++) if(r<q[i].l) r=q[i].r,ans++;
	printf("%d",ans);
	return 0;
}
