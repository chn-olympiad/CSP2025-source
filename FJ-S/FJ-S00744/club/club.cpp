#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,f[100005],s[100005],num1,num2,num3,p[100005],k;
long long ans;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) f[i]=s[i]=p[i]=0;
		num1=num2=num3=k=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			int maxx=max(a,max(b,c));
			if(maxx==a)
			{
				s[i]=a-max(b,c);
				f[i]=1;
				num1++;
			}
			else if(maxx==b)
			{
				s[i]=b-max(a,c);
				f[i]=2;
				num2++;
			}
			else
			{
				s[i]=c-max(a,b);
				f[i]=3;
				num3++;
			}
			ans+=maxx;
		}
		int flag=0,d=max(max(num1,num2),num3)-n/2;
		if(num1>n/2) flag=1;
		else if(num2>n/2) flag=2;
		else if(num3>n/2) flag=3;
		if(!flag) printf("%lld\n",ans);
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i]==flag) p[++k]=s[i];
			}
			sort(p+1,p+1+k);
			for(int i=1;i<=d;i++) ans-=p[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
