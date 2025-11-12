#include<bits/stdc++.h>
using namespace std;
int aaa[100005];
int t,n,as,bs,cs,ans,s1,cnt;
int a[100005],m[100005],
b[100005],c[100005];
int cmp(int x,int y)
{
	return x<y;
}
void cla()
{
	for(int i=1;i<=n;i++)
	{
		if(m[i]==1)
		{
			aaa[++cnt]=min(a[i]-b[i],a[i]-c[i]);
		}
	}
	sort(aaa+1,aaa+cnt+1,cmp);
	for(int i=1;i<=as-n/2;i++)
	{
		s1+=aaa[i];
	}
}
void clb()
{
	for(int i=1;i<=n;i++)
	{
		if(m[i]==2)
		{
			aaa[++cnt]=min(b[i]-a[i],b[i]-c[i]);
		}
	}
	sort(aaa+1,aaa+cnt+1,cmp);
	for(int i=1;i<=bs-n/2;i++)
	{
		s1+=aaa[i];
	}
}
void clc()
{
	for(int i=1;i<=n;i++)
	{
		if(m[i]==3)
		{
			aaa[++cnt]=min(c[i]-b[i],c[i]-a[i]);
		}
	}
	sort(aaa+1,aaa+cnt+1,cmp);
	for(int i=1;i<=cs-n/2;i++)
	{
		s1+=aaa[i];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		s1=0,ans=0,as=0,bs=0,cs=0,cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				as+=1,m[i]=1,ans+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				bs+=1,m[i]=2,ans+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				cs+=1,m[i]=3,ans+=c[i];
			}
		}
		if(as>n/2)
		{
			cla();
		}
		else if(bs>n/2)
		{
			clb();
		}
		else if(cs>n/2)
		{
			clc();
		}
		printf("%d\n",ans-s1);
	}
	
	return 0;
}

