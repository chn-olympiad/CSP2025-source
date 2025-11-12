#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct node
{
	int v,p,d;
}a[100005];
int b[100005];
bool cmp1(node x,node y)
{
	return x.v>y.v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t=read();
	while(t--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
		{
			int x=read(),y=read(),z=read();
			if(x>=y && x>=z)
			{
				a[i].v=x,a[i].p=1;
				if(y>z) a[i].d=x-y;
				else a[i].d=x-z;
			}
			else if(y>=x && y>=z)
			{
				a[i].v=y,a[i].p=2;
				if(x>z) a[i].d=y-x;
				else a[i].d=y-z;
			}
			else
			{
				a[i].v=z,a[i].p=3;
				if(x>y) a[i].d=z-x;
				else a[i].d=z-y;
			}
		}
		sort(a+1,a+n+1,cmp1);
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].v;
			if(a[i].p==1) cnt1++;
			else if(a[i].p==2) cnt2++;
			else cnt3++;
		}
		memset(b,0,sizeof b);
		int cnt=0;
		if(cnt1>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].p==1) b[++cnt]=a[i].d;
		}
		else if(cnt2>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].p==2) b[++cnt]=a[i].d;
		}
		else if(cnt3>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].p==3) b[++cnt]=a[i].d;
		}
		else {write(ans);putchar('\n');continue;}
		sort(b+1,b+cnt+1);
		for(int i=1;cnt>n/2;i++)
			ans-=b[i],cnt--;
		write(ans);
		putchar('\n');
	}
	return 0;
}
