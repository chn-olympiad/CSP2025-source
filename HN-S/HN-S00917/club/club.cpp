#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct Stu
{
	int maxn,minn,mid;
	int maxnid,minnid,midid;
}a[N];
int b[N],c[N],d[N];
bool cmpb(int x,int y)
{
	return a[x].maxn-a[x].mid>a[y].maxn-a[y].mid;
}
bool cmpc(int x,int y)
{
	return a[x].maxn-a[x].mid>a[y].maxn-a[y].mid;
}
bool cmpd(int x,int y)
{
	return a[x].maxn-a[x].mid>a[y].maxn-a[y].mid;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	while(t--)
	{
		int cnt1=0,cnt2=0,cnt3=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&y>=z) a[i].maxn=x,a[i].mid=y,a[i].minn=z,a[i].maxnid=1,a[i].midid=2,a[i].minnid=3;
			else if(x>=z&&z>=y) a[i].maxn=x,a[i].mid=z,a[i].minn=y,a[i].maxnid=1,a[i].midid=3,a[i].minnid=2;
			else if(y>=x&&x>=z) a[i].maxn=y,a[i].mid=x,a[i].minn=z,a[i].maxnid=2,a[i].midid=1,a[i].minnid=3;
			else if(y>=z&&z>=x) a[i].maxn=y,a[i].mid=z,a[i].minn=x,a[i].maxnid=2,a[i].midid=3,a[i].minnid=1;
			else if(z>=y&&y>=x) a[i].maxn=z,a[i].mid=y,a[i].minn=x,a[i].maxnid=3,a[i].midid=2,a[i].minnid=1;
			else a[i].maxn=z,a[i].mid=x,a[i].minn=y,a[i].maxnid=3,a[i].midid=1,a[i].minnid=2;
			if(a[i].maxnid==1) b[++cnt1]=i;
			else if(a[i].maxnid==2) c[++cnt2]=i;
			else d[++cnt3]=i;
		}	
//		cout<<endl;
		sort(b+1,b+cnt1+1,cmpb);
		sort(c+1,c+cnt2+1,cmpc);
		sort(d+1,d+cnt3+1,cmpd);
		int sum=0;
		for(int i=n/2+1;i<=cnt1;i++) sum+=a[b[i]].mid;
		for(int i=n/2+1;i<=cnt2;i++) sum+=a[c[i]].mid;
		for(int i=n/2+1;i<=cnt3;i++) sum+=a[d[i]].mid;
		for(int i=1;i<=min(n/2,cnt1);i++) sum+=a[b[i]].maxn;
		for(int i=1;i<=min(n/2,cnt2);i++) sum+=a[c[i]].maxn;
		for(int i=1;i<=min(n/2,cnt3);i++) sum+=a[d[i]].maxn;
//		for(int i=1;i<=cnt1;i++) sum+=a[b[i]].maxn;
//		for(int i=1;i<=cnt2;i++) sum+=a[c[i]].maxn;
//		for(int i=1;i<=cnt3;i++) sum+=a[d[i]].maxn;	
//		for(int i=1;i<=cnt3;i++)
//		{
//			cout<<a[d[i]].maxn-a[d[i]].mid<<" "<<i<<endl;
//		}
		cout<<sum<<endl;
	}
	return 0;
} 
