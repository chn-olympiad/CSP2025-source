#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001],c[100001],n,t,s;
int da[100001],db[100001],dc[100001],m[100001],as,bs,cs;

void init()
{
	for(int i=0;i<100001;i++)
	{
		a[i]=b[i]=c[i]=da[i]=db[i]=dc[i]=m[i]=0;
	}
	as=bs=cs=s=0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--)
	{
		init(); 
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>b[i])
			{
				if(a[i]>c[i])
				{
					m[i]=a[i];
					da[i]=a[i]-max(b[i],c[i]);
					db[i]=dc[i]=INT_MAX;
					as++;
				}
				else
				{
					m[i]=c[i];
					dc[i]=c[i]-a[i];
					da[i]=db[i]=INT_MAX;
					cs++;
				}
			}
			else
			{
				if(b[i]>c[i])
				{
					m[i]=b[i];
					db[i]=b[i]-max(a[i],c[i]);
					da[i]=dc[i]=INT_MAX;
					bs++;
				}
				else
				{
					m[i]=c[i];
					dc[i]=c[i]-b[i];
					da[i]=db[i]=INT_MAX;
					cs++;
				}
			}
			s=s+m[i];
		}
		int o=max(as,max(bs,cs))-n/2;
		if(as>n/2)
		{
			sort(da+1,da+n+1);
			for(int i=1;i<=o;i++)
			{
				s=s-da[i];
			}
		}
		if(bs>n/2)
		{
			sort(db+1,db+n+1);
			for(int i=1;i<=o;i++)
			{
				s=s-db[i];
			}
		}
		if(cs>n/2)
		{
			sort(dc+1,dc+n+1);
			for(int i=1;i<=o;i++)
			{
				s=s-dc[i];
			}
		}
		printf("%d\n",s);
	}
	return 0;
}

