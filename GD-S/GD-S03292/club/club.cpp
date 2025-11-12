#include<bits/stdc++.h>
using namespace std;
int t,n,cnt1,cnt2,cnt3,ans;
struct N
{
	int x,mx,nx;
}c1[100001],c2[100001],c3[100001];
bool cmp(N x,N y)
{
	return x.x>y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=n;i++)
		{
			int xf,yf,zf;
			scanf("%d%d%d",&xf,&yf,&zf);
			if(xf>=max(yf,zf))
			{
				c1[++cnt1].x=xf-max(yf,zf);
				c1[cnt1].mx=xf;c1[cnt1].nx=max(yf,zf);
			}
			else if(yf>=max(xf,zf))
			{
				c2[++cnt2].x=yf-max(xf,zf);
				c2[cnt2].mx=yf;c2[cnt2].nx=max(xf,zf);
			}
			else
			{
				c3[++cnt3].x=zf-max(yf,xf);
				c3[cnt3].mx=zf;c3[cnt3].nx=max(yf,xf);
			}
		}
		sort(c1+1,c1+cnt1+1,cmp);sort(c2+1,c2+cnt2+1,cmp);sort(c3+1,c3+cnt3+1,cmp);
		for(int i=1;i<=cnt1;i++)
		{
			if(i>n/2) ans+=c1[i].nx;
			else ans+=c1[i].mx;
		}
		for(int i=1;i<=cnt2;i++)
		{
			if(i>n/2) ans+=c2[i].nx;
			else ans+=c2[i].mx;
		}
		for(int i=1;i<=cnt3;i++)
		{
			if(i>n/2) ans+=c3[i].nx;
			else ans+=c3[i].mx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
