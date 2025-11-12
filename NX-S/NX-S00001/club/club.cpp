#include <bits/stdc++.h>
using namespace std;

struct point
{
	int p1,p2;
};
point x[100010],y[100010],z[100010];
int x2[100010],y2[100010],z2[100010];
int q[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x2[i]>>y2[i]>>z2[i];
		}
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++)
		{
			if(max(x2[i],max(y2[i],z2[i]))==x2[i])
			{
				c1++;
				c=c+x2[i];
				x[c1].p1=i;
				x[c1].p2=x2[i];
			}
			else if(max(x2[i],max(y2[i],z2[i]))==y2[i])
			{
				c2++;
				c=c+y2[i];
				y[c2].p1=i;
				y[c2].p2=y2[i];
			}
			else
			{
				c3++;
				c=c+z2[i];
				z[c3].p1=i;
				z[c3].p2=z2[i];
			}
		}
		
		if(c1<=n/2&&c2<=n/2&&c3<=n/2)
			cout<<c<<endl;
		else
		{
			if(c1>n/2)
			{
				for(int i=1;i<=c1;i++)
				{
					int v=x[i].p1;
					q[i]=x[i].p2-max(y2[v],z2[v]);
							
				}
				for(int i=1;i<=c1-n/2;i++)
				{
					sort(q+1,q+c1+1);
					c=c-q[i];
				}
			}
			//1
			else if(c2>n/2)
			{
				for(int i=1;i<=c2;i++)
				{
					int v=y[i].p1;
					q[i]=y[i].p2-max(x2[v],z2[v]);
							
				}
				for(int i=1;i<=c2-n/2;i++)
				{
					sort(q+1,q+c1+1);
					c=c-q[i];
				}
			}
			//2
			else
			{
				for(int i=1;i<=c3;i++)
				{
					int v=z[i].p1;
					q[i]=z[i].p2-max(y2[v],x2[v]);
							
				}
				for(int i=1;i<=c3-n/2;i++)
				{
					sort(q+1,q+c1+1);
					c=c-q[i];
				}
			}
			//3
			cout<<c<<endl;
			
		}
		
		for(int i=1;i<=n;i++)
			{
				x[i].p1=0;
				x[i].p2=0;
				y[i].p1=0;
				y[i].p2=0;
				z[i].p1=0;
				z[i].p2=0;
				x2[i]=0;
				y2[i]=0;
				z2[i]=0;
				q[i]=0;
			}
	}
	
	
	return 0;
}


