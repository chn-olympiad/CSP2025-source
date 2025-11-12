#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f3f3f3f3f;
inline int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') num=num*10+c-'0',c=getchar();
	return num*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10),x%=10;
	putchar(x+'0');
}
int n,t,cnt[5],ans,n1;
struct node
{
	int a,b,c,maxid;
}a[N];
bool cmp(node a1,node a2)
{
	if(a1.maxid==a2.maxid)
	{
		if(a1.maxid==1) return min(a1.a-a1.b,a1.a-a1.c)>=min(a2.a-a2.b,a2.a-a2.c);
		if(a1.maxid==2) return min(a1.b-a1.a,a1.b-a1.c)>=min(a2.b-a2.a,a2.b-a2.c);
		if(a1.maxid==3) return min(a1.c-a1.a,a1.c-a1.b)>=min(a2.c-a2.a,a2.c-a2.b);
	}
	return a1.maxid<a2.maxid;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),n1=n>>1,ans=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) 
		{
			a[i].a=read(),a[i].b=read(),a[i].c=read();
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c) a[i].maxid=1;
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) a[i].maxid=2;
			else a[i].maxid=3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxid==1)
			{
				if(cnt[1]<n1) cnt[1]++,ans+=a[i].a;
				else ans+=max(a[i].c,a[i].b);
			}
			else if(a[i].maxid==2)
			{
				if(cnt[2]<n1) cnt[2]++,ans+=a[i].b;
				else ans+=max(a[i].a,a[i].c);
			}
			else
			{
				if(cnt[3]<n1) cnt[3]++,ans+=a[i].c;
				else ans+=max(a[i].a,a[i].b);
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
