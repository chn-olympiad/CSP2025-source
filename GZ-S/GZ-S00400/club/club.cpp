//SZ-S00400 遵义市南白中学 袁双全 
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node
{
	int x;
	int y;
	int z;
}a[100005];
int c[100005],d[100005],e[100005];
long long f[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long ans=0;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		int cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x;
			cin>>a[i].y;
			cin>>a[i].z;
		}
		for(int i=1;i<=n;i++)
		{
			int maxn=max(a[i].x,max(a[i].y,a[i].z));
			ans+=maxn;
			if(maxn==a[i].x)
			c[++cnt1]=i;
			else if(maxn==a[i].y)
			d[++cnt2]=i;
			else
			e[++cnt3]=i;
		}
		int maxn=max(cnt1,max(cnt2,cnt3));
//		cout<<maxn<<endl;
		if(maxn>n/2)
		{
			if(maxn==cnt1)
			for(int i=1;i<=cnt1;i++)
			f[i]=max(a[c[i]].y-a[c[i]].x,a[c[i]].z-a[c[i]].x);
			else
			if(maxn==cnt2)
			for(int i=1;i<=cnt2;i++)
			f[i]=max(a[d[i]].x-a[d[i]].y,a[d[i]].z-a[d[i]].y);
			else
			for(int i=1;i<=cnt3;i++)
			f[i]=max(a[e[i]].x-a[e[i]].z,a[e[i]].y-a[e[i]].z);
//				for(int i=1;i<=maxn;i++)
//			cout<<f[i]<<" ";
			sort(f+1,f+1+maxn);
//			cout<<endl;
			for(int i=maxn;i>n/2;i--)
			{
				ans+=f[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
