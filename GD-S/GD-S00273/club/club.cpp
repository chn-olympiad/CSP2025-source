#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+c-'0',c=getchar();
	return ret;
}
int t,n,ans;
struct A
{
	int x,y,z;
}a[100010];
int cnt,b[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read(); 
	while(t--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i].x=read(),a[i].y=read(),a[i].z=read();
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>a[i].y)
			{
				if(a[i].x>a[i].z)
				{
					ans+=a[i].x,cnt1++;
				}
				else ans+=a[i].z,cnt3++;
			}
			else
			{
				if(a[i].y>a[i].z)
				{
					ans+=a[i].y,cnt2++;
				}
				else ans+=a[i].z,cnt3++;
			}
		}
		if(cnt1>n/2)
		{
			memset(b,0,sizeof(b));
			int d=cnt1-n/2;
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].x>a[i].y&&a[i].x>a[i].z)
					b[++cnt]=a[i].x-max(a[i].y,a[i].z);
			}
			sort(b+1,b+cnt+1);
			for(int i=1;i<=d;i++) ans-=b[i];
		}
		else if(cnt2>n/2)
		{
			memset(b,0,sizeof(b));
			int d=cnt2-n/2;
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].x<=a[i].y&&a[i].y>a[i].z)
					b[++cnt]=a[i].y-max(a[i].x,a[i].z);
			}
			sort(b+1,b+cnt+1);
			for(int i=1;i<=d;i++) ans-=b[i];
		}
		else if(cnt3>n/2)
		{
			memset(b,0,sizeof(b));
			int d=cnt3-n/2;
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z>=a[i].y&&a[i].x<=a[i].z)
					b[++cnt]=a[i].z-max(a[i].y,a[i].x);
			}
			sort(b+1,b+cnt+1);
			for(int i=1;i<=d;i++) ans-=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

