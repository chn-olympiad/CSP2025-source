#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=200010;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int T;
int t,cnt1,cnt2,cnt3;
int vis[N],del[N];
struct node
{
	int x,y,z;
}a[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		int n;
		n=read();
		int limit=n/2,sum=0;
		t=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++) vis[i]=del[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i].x=read();a[i].y=read();a[i].z=read();
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) sum+=a[i].x,cnt1++,vis[i]=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) sum+=a[i].y,cnt2++,vis[i]=2;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) sum+=a[i].z,cnt3++,vis[i]=3;
		}
		if(cnt1>limit)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]!=1) continue;
				int maxn=max(a[i].y,a[i].z);
				del[++t]=a[i].x-maxn;
			}
			sort(del+1,del+1+t);
			for(int i=1;i<=cnt1-limit;i++) sum-=del[i];
		}
		else if(cnt2>limit)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]!=2) continue;
				int maxn=max(a[i].x,a[i].z);
				del[++t]=a[i].y-maxn;
			}
			sort(del+1,del+1+t);
			for(int i=1;i<=cnt2-limit;i++) sum-=del[i];
		}
		else if(cnt3>limit)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]!=3) continue;
				int maxn=max(a[i].x,a[i].y);
				del[++t]=a[i].z-maxn;
			}
			sort(del+1,del+1+t);
			for(int i=1;i<=cnt3-limit;i++) sum-=del[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
//Bocchi the Rock! 