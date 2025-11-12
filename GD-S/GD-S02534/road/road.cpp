#include<bits/stdc++.h>
using namespace std;
struct data
{
	int x,y,z;
}a[1000005];
bool cmp(data x,data y)
{
	return x.z<y.z;
}
int n,m,k,p,l;
int f[10005];
int b[15];
int rt(int z)
{
	if(f[z]==z)
	{
		return z;
	}
	else 
	{
		return rt(f[z]);
	}
}
void uio(int x,int y)
{
	f[x]=y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	l=m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		f[i]=a[i].x;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&b[i]);
		for(int j=1;j<=n;j++)
		{
			int yi;
			scanf("%d",&yi);
			l+=1;
			p+=1;
			a[l].x=p;
			a[l].y=j;
			a[l].z=yi;
		}
	}
	sort(a+1,a+1+l,cmp);
	int x=1;
	int sum=a[1].z;
	for(int i=2;i<=l;i++)
	{
		if(rt(x)!=rt(i))
		{
			uio(x,i);
			if(i<=m)
			{
				sum+=a[i].z;
			}
			else
			{
				sum+=a[i].z+b[i-m];
				b[i-m]=0;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
