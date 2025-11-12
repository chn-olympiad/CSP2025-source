#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005];
long long ans,c[5005][5005],sc[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool p=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		if(a[i]!=1) p=1;
	}
	sort(a+1,a+1+n);
	if(n<3) 
	{
		printf("0");
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]<=a[3]) printf("0");
		else printf("1");
		return 0;
	}
	if(!p)
	{
		printf("%d",n/3);
		return 0;
	}
	sc[1]=1;
	for(int i=1;i<=n;i++) c[i][1]=i;
	for(int i=1;i<=n;i++)
		for(int j=2;j<=i;j++) 
		{
			c[i][j]=1LL*c[i][j-1]*(i-j+1)/j;
			c[i][j]%=mod;
			sc[i]+=c[i][j];
			sc[i]%=mod;
		}
	for(int r=n;r>=1;r--)
	{
		bool p=0;
		for(int l1=1;l1<r&&!p;l1++)
		{
			for(int l2=l1;l2<r&&!p;l2++)
			{
				if(s[l2]-s[l1-1]>a[r])
				{
					p=1;
					while(s[l2]-s[l1-1]>r && l1<l2) 
					{
						ans+=(sc[r-l2]+sc[l1-1])%mod;
						l1++;
					}
					ans%=mod;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
