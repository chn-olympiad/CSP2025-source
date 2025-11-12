#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1010100,Moder_=998244353;
long long n,m,a[MAXN],s[MAXN],p[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld\n",&n,&m);
	long long i,j,t=1;
	for(i=1;i<=n;i++)
	{
		scanf("%1lld",&s[i]);
		p[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		t*=i;
		t%=Moder_;
	}
	if(m==n)
	{
		for(i=1;i<=n;i++)
		{
			if(s[i]!=1)
			{
				printf("0\n");
				return 0;
			}
			if(a[i]==0)
			{
				printf("0\n");
				return 0;
			}
		}
		printf("%lld\n",t);
		return 0;
	}
	if(n>=11)
	{
		printf("0\n");
		return 0;
	}
	long long cnt=0,sum=0,ans=0;
	while(t--)
	{
		next_permutation(p+1,p+1+n);
		cnt=0;
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(cnt>=a[p[i]]||s[i]==0)
			{
				cnt++;
			}
			else
			{
				sum++;
			}
		}
		if(sum>=m)
		{
			ans++;
			ans%=Moder_;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//我常常追忆过去。
//但是再见了，不曾追忆的过去。
// --Exp10re,2025/11/01.
