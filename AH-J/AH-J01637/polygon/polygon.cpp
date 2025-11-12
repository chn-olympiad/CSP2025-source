#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[5005];
int f[5005][5005];//f[i][j] is (in 1~i-1 >j ?ge)
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int Max=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Max=max(Max,a[i]);
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			for(int j=Max;j>=0;j--)
			{
				f[i][j]=f[i-1][j];
				if(j>=a[i-1]) f[i][j]=(f[i][j]+f[i-1][j-a[i]])%Mod;
			}
		}
		sum=0;
		for(int j=0;j<=a[i];j++)
		{
			sum+=f[i-1][j];
			sum%=Mod;
		}
		long long cnt=1;
		for(int j=1;j<=i-1;j++)
		{
			cnt*=2;
			cnt%=Mod;
		}
		ans=(ans+(((cnt-sum)%Mod+Mod)%Mod))%Mod;
	}
	printf("%lld",ans);
	return 0;
}
/*
5
2 2 3 8 10

1 1 
1 1 1 1 
1 1 1 2 1 1 1 
1 1 1 2 2 2 2 2 1 1 1 
1 1 1 2 2 3 3 3 3 3 3 2 2 1 1 1
*/
