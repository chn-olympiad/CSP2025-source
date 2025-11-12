#include<stdio.h>
#include<algorithm>
int qread(void)
{
	int sign=1,num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return sign*num;
}
int a[100010],b[100010],c[100010];
int cho[100010],val[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=qread();
	while(T--)
	{
		int n=qread();
		for(int i=1;i<=n;i++)
		{
			a[i]=qread();
			b[i]=qread();
			c[i]=qread();
		}
		int suma=0,sumb=0,sumc=0,ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				cho[i]=1;
				ans+=a[i];
				suma++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				cho[i]=2;
				ans+=b[i];
				sumb++;
			}
			else
			{
				cho[i]=3;
				ans+=c[i];
				sumc++;
			}
		if(suma>n/2)
		{
			int x=0;
			for(int i=1;i<=n;i++)
				if(cho[i]==1)
					val[++x]=std::min(a[i]-b[i],a[i]-c[i]);
			std::sort(val+1,val+1+x);
			int pos=1;
			while(suma>n/2)
			{
				ans-=val[pos];
				pos++;
				suma--;
			}
		}
		if(sumb>n/2)
		{
			int x=0;
			for(int i=1;i<=n;i++)
				if(cho[i]==2)
					val[++x]=std::min(b[i]-a[i],b[i]-c[i]);
			std::sort(val+1,val+1+x);
			int pos=1;
			while(sumb>n/2)
			{
				ans-=val[pos];
				pos++;
				sumb--;
			}
		}
		if(sumc>n/2)
		{
			int x=0;
			for(int i=1;i<=n;i++)
				if(cho[i]==3)
					val[++x]=std::min(c[i]-a[i],c[i]-b[i]);
			std::sort(val+1,val+1+x);
			int pos=1;
			while(sumc>n/2)
			{
				ans-=val[pos];
				pos++;
				sumc--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
