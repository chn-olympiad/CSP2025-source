#include <bits/stdc++.h>
using namespace std;
int a[5];
int t,n,d[100005],e[100005],f[100005];
int b[100005],x[100005],y[100005],z[100005],c[100005];
struct d{
	int a1;
	int a2;
	int a3;
}myd[100005];
bool cmp(int x,int h){
	return x>h;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n>=2)
		{
				for(int j=0;j<n;j++)
			{
				cin>>myd[j].a1>>myd[j].a2>>myd[j].a3;
				x[j]=max(myd[j].a1,myd[j].a2);
				if(myd[j].a1>myd[j].a2){
					c[j]=1;
				}
				else
				{
					c[j]=2;
				}
				y[j]=max(myd[j].a3,x[j]);
				if(myd[j].a3>x[j])
				{
					z[j]=3;
				}
				else
				{
					z[j]=c[j];
				}
				if(myd[j].a2==myd[j].a3==0)
				{
					b[j]=myd[j].a1;
				}
			}
		sort(b,b+n);
		for(int j=0;j<n;j++)
		{
			if(myd[j].a2==myd[j].a3==0)
			{
				cout<<b[0];
				return 0;
			}
			if(z[j]==3&&c[j]==2)
			{
				d[j]=myd[j].a3;
				e[j]=myd[j].a2;
				f[j]=myd[j].a1;
			}
			if(z[j]==3&&c[j]==1)
			{
				d[j]=myd[j].a3;
				e[j]=myd[j].a1;
				f[j]=myd[j].a2;
			}
			if(z[j]==2&&c[j]==1){
				d[j]=myd[j].a2;
				e[j]=myd[j].a1;
				f[j]=myd[j].a3;
			}
			if(z[j]==2&&c[j]==2)
			{
				d[j]=myd[j].a2;
				e[j]=myd[j].a3;
				f[j]=myd[j].a1;
			}
			if(z[j]==1&&c[j]==1){
				d[j]=myd[j].a1;
				e[j]=myd[j].a2;
				f[j]=myd[j].a3;
			}
		}
		}
		for(int j=0;j<n;j++)
		{
			cout<<d[j]+e[j]+f[j];
		}
	}
	return 0;
}
