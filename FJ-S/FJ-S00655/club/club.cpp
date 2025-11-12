#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],maxn[100010][13],m1[100010],m2[100010],m3[100010],xx,yy,zz;
long long s=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=b[j] && a[j]>=c[j])
			{
				maxn[j][1]=a[j];
				maxn[j][2]=max(b[j],c[j]);
				xx++;
				m1[xx]=abs(maxn[j][1]-maxn[j][2]);
			}
			else if(b[j]>=a[j] && b[j]>=c[j])
			{
				maxn[j][2]=b[j];
				maxn[j][1]=max(a[j],c[j]);
				yy++;
				m2[yy]=abs(maxn[j][1]-maxn[j][2]);
			}
			else
			{
				maxn[j][2]=c[j];
				maxn[j][1]=max(a[j],b[j]);
				zz++;
				m3[zz]=abs(maxn[j][1]-maxn[j][2]);
			}
		}
		sort(m1+1,m1+xx+1);
		sort(m2+1,m2+yy+1);
		sort(m3+1,m3+n-xx-yy+1);
		for(int j=1;j<=n;j++)
		{
			s+=max(maxn[j][1],maxn[j][2]);
			if(xx>n/2)
			{
				if(j<=abs(xx-n/2))
				{
					s-=m1[j];
				}
			}
			if(yy>n/2)
			{
				if(j<=abs(yy-n/2))
				{
					s-=m2[j];
				}
			}
			if(zz>n/2)
			{
				if(j<=abs(zz-n/2))
				{
					s-=m3[j];
				}
			}
			
		}
		cout<<s<<endl;
		s=0;xx=0;yy=0;
	}
	
	return 0;
}
