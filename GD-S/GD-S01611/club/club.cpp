#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],b[100005],x[100005],y[100005],z[100005],xn,yn,zn,flag;
long long ans;
bool cmp(int x,int y)
{
	return b[x]<b[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin >> t;
	for (int l=0;l<t;l++)
	{
		for (int i=0;i<xn;i++)
		{
			x[i]=0;
		}
		for (int i=0;i<yn;i++)
		{
			y[i]=0;
		}
		for (int i=0;i<zn;i++)
		{
			z[i]=0;
		}
		xn=0;
		yn=0;
		zn=0;
		ans=0;
		cin >> n;
		for (int i=0;i<n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		for (int i=0;i<n;i++)
		{
			if ((a[i][0]>=a[i][1])&&(a[i][0]>=a[i][2]))
			{
				flag=0;
				b[i]=a[i][0]-max(a[i][1],a[i][2]);
				if (xn+1<=n/2)
				{
					x[xn]=i;
					xn++;
				}
				else
				{
					sort(x,x+xn,cmp);
					if (a[i][1]>=a[i][2])
					{
						y[yn]=x[0];
						yn++; 
					}
					else
					{
						z[zn]=x[0];
						zn++;
					}
					x[0]=i;
				}
			}
			else if ((a[i][1]>=a[i][0])&&(a[i][1]>=a[i][2]))
			{
				flag=1;
				b[i]=a[i][1]-max(a[i][0],a[i][2]);
				if (yn+1<=n/2)
				{
					y[yn]=i;
					yn++;
				}
				else
				{
					sort(y,y+yn,cmp);
					if (a[i][0]>=a[i][2])
					{
						x[xn]=y[0];
						xn++; 
					}
					else
					{
						z[zn]=y[0];
						zn++;
					}
					y[0]=i;
				}
			}
			else
			{
				flag=2;
				b[i]=a[i][2]-max(a[i][0],a[i][1]);
				if (zn+1<=n/2)
				{
					z[zn]=i;
					zn++;
				}
				else
				{
					sort(z,z+zn,cmp);
					if (a[i][0]>=a[i][1])
					{
						x[xn]=z[0];
						xn++; 
					}
					else
					{
						y[yn]=z[0];
						yn++;
					}
					z[0]=i;
				}
			}
		}
		for (int i=0;i<xn;i++)
		{
			ans+=a[x[i]][0];
		}
		for (int i=0;i<yn;i++)
		{
			ans+=a[y[i]][1];
		}
		for (int i=0;i<zn;i++)
		{
			ans+=a[z[i]][2];
		}
		cout << ans << endl;
	}
} 
