#include <bits/stdc++.h>
using namespace std;
#define int long long
struct st 
{
	int	n1,n2,n3;
	int p1,p2,mx1,mx2,num;
}a[100010];
int d[4];
int n,T,ans;
bool cmp(st xx,st yy)
{
	return xx.num>yy.num;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{ans=0;
		cin>>n;
		int mxn=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			int mx=max(a[i].n1,max(a[i].n2,a[i].n3)),mxx;
			if(a[i].n1==mx)a[i].p1=1;
			else if(a[i].n2==mx)a[i].p1=2;
			else if(a[i].n3==mx)a[i].p1=3;
			if(a[i].p1==1)
			{
				if(a[i].n2>=a[i].n3)a[i].p2=2;
				else a[i].p2=3;
			}
			else if(a[i].p1==2)
			{
				if(a[i].n1>=a[i].n3)a[i].p2=1;
				else a[i].p2=3;
			}
			else if(a[i].p1==3)
			{
				if(a[i].n1>=a[i].n2)a[i].p2=1;
				else a[i].p2=2;
			}
			a[i].mx1=mx;
			if(a[i].p2==1)a[i].mx2=a[i].n1;
			if(a[i].p2==2)a[i].mx2=a[i].n2;
			if(a[i].p2==3)a[i].mx2=a[i].n3;
			a[i].num=a[i].mx1-a[i].mx2;
			
			
		}
		sort(a+1,a+1+n,cmp);
		
		for(int i=1;i<=n;i++)
		{
			if(d[a[i].p1]<mxn)
			{
				d[a[i].p1]++;
				ans+=a[i].mx1;
			}
			else 
			{
				d[a[i].p2]++;
				ans+=a[i].mx2;
			}
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}
