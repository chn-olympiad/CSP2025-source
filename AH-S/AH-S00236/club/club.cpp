#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],a1,b1,c1,ac[20005],ca[20005],ab[20005],ba[20005],cb[20005],bc[20005],ans=0,ls;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		a1=0;b1=0;c1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i])
			{
				a1++;
				ac[a1]=a[i]-c[i];
				ab[a1]=a[i]-b[i];
			}
			else if(b[i]>a[i]&&b[i]>c[i])
			{
				b1++;
				ba[b1]=b[i]-a[i];
				bc[b1]=b[i]-c[i];
			}
			else if(c[i]>a[i]&&c[i]>b[i])
			{
				c1++;
				ca[c1]=c[i]-a[i];
				cb[c1]=c[i]-b[i];
			}
			ans+=max(max(a[i],b[i]),c[i]);
		}
		if(a1<=n/2&&b1<=n/2&&c1<=n/2)
		{
			ans=ans;
		}
		else
		{
			if(a1>n/2)
			{
				if(b1<n/2)
				{
					sort(ab+1,ab+a1+1);
				}
				if(c1<n/2)
				{
					sort(ac+1,ac+a1+1);
					
				}int e2=1;
				for(int e1=1;a1-e1-e2+2>n/2;e1=e1)
				{
					if(c1<n/2)
					{
						ls=ac[e1];
						c1++;
						e1++;
					}
					if(b1<n/2&&ab[e2]<ls)
					{
						ls=ab[e2];
						c1--;
						e1--;
						b1++;
						e2++;
					}
					ans-=ls;
				}
			}
			if(b1>n/2)
			{
				if(a1<n/2)
				{
					sort(ba+1,ba+b1+1);
				}
				if(c1<n/2)
				{
					sort(bc+1,bc+b1+1);
				}
				int e2=1;
				for(int e1=1;b1-e1-e2+2>n/2;e1=e1)
				{
					ls=INT_MAX;
					if(c1<n/2)
					{
						ls=bc[e1];
						c1++;
						e1++;
					}
					if(a1<n/2&&ba[e2]<ls)
					{
						ls=ba[e2];
						c1--;
						e1--;
						a1++;
						e2++;
					}
					ans-=ls;
				}
			}
			if(c1>n/2)
			{
				if(b1<n/2)
				{
					sort(cb+1,cb+c1+1);
				}
				if(a1<n/2)
				{
					sort(ca+1,ca+c1+1);
					
				}int e2=1;
				for(int e1=1;c1-e1-e2+2>n/2;e1=e1)
				{
					if(a1<n/2)
					{
						ls=ca[e1];
						a1++;
						e1++;
					}
					if(b1<n/2&&cb[e2]<ls)
					{
						ls=cb[e2];
						a1--;
						e1--;
						b1++;
						e2++;
					}
					ans-=ls;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
