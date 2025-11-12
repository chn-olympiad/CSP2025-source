#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][4],xl[4],x[100005],mx,sl[100005],flg=0,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	for(int T=1;T<=t;T++)
	{
		sum=0;
		xl[1]=0;
		xl[2]=0;
		xl[3]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])xl[1]++,x[i]=1,sum+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])xl[2]++,x[i]=2,sum+=a[i][2];
			else xl[3]++,x[i]=3,sum+=a[i][3];
		}
		if(xl[1]>xl[2])mx=1;
		else mx=2;
		if(xl[3]>xl[mx])mx=3;
		long long ans=0;
		flg=0;
		if(xl[mx]>n/2)
		{
			for(int i=1;i<=n;i++)if(x[i]==mx)sl[++flg]=a[i][mx]-max(a[i][(mx+1)%3],a[i][(mx+2)%3]);
			sort(sl+1,sl+xl[mx]+1);
			for(int i=1;i<=xl[mx]-n/2;i++)ans+=sl[i];
		}
		printf("%lld\n",sum-ans);
	}
	return 0;
}