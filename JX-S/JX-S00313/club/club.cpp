#include<bits/stdc++.h>
using namespace std;
int t,n,b[100010],c[5],mxjcmxx[100010],ans;
struct node
{
	int d1,d2,d3;
	int mx,mxid;
	int cmx,cmxid;
	int mxjcmx;
}a[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(mxjcmxx,0,sizeof(mxjcmxx));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].mx=max(max(a[i].d1,a[i].d2),a[i].d3);
			if(a[i].d1>=a[i].d2 && a[i].d1>=a[i].d3)
			{
				a[i].mx=a[i].d1;
				a[i].mxid=1;
			}
			else if(a[i].d2>=a[i].d1 && a[i].d2>=a[i].d3)
			{
				a[i].mx=a[i].d2;
				a[i].mxid=2;
			}
			else
			{
				a[i].mx=a[i].d3;
				a[i].mxid=3;
			}
			if((a[i].d1>=a[i].d2 && a[i].d1<=a[i].d3) || (a[i].d1>=a[i].d3 && a[i].d1<=a[i].d2))
			{
				a[i].cmx=a[i].d1;
				a[i].cmxid=1;
			}
			else if((a[i].d2>=a[i].d1 && a[i].d2<=a[i].d3) || (a[i].d2>=a[i].d3 && a[i].d2<=a[i].d1))
			{
				a[i].cmx=a[i].d2;
				a[i].cmxid=2;
			}
			else
			{
				a[i].cmx=a[i].d3;
				a[i].cmxid=3;
			}
			a[i].mxjcmx=a[i].mx-a[i].cmx;
			ans+=a[i].mx;
			//cout<<a[i].cmx<<" ";
		}
		for(int i=1;i<=n;i++)
		{
			c[a[i].mxid]++;
			
		}
		int u=0;
		if(c[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].mxid==1)mxjcmxx[++u]=a[i].mxjcmx;
			}
			sort(mxjcmxx+1,mxjcmxx+1+u);
			for(int i=1;i<=u-n/2;i++)
			{
				ans-=mxjcmxx[i];
			}
		}
		else if(c[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].mxid==2)mxjcmxx[++u]=a[i].mxjcmx;
			}
			sort(mxjcmxx+1,mxjcmxx+1+u);
			for(int i=1;i<=u-n/2;i++)
			{
				ans-=mxjcmxx[i];
			}
		}
		else if(c[3]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].mxid==3)mxjcmxx[++u]=a[i].mxjcmx;
			}
			sort(mxjcmxx+1,mxjcmxx+1+u);
			for(int i=1;i<=u-n/2;i++)
			{
				ans-=mxjcmxx[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
