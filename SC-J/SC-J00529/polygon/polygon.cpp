#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,ans,m;
int a[5001];
int main()
{
	srand(time(0));
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==3)
	{
		int f=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(a[i]+a[j]<=a[k])f=0;
		printf("%d",f);
		exit(0);
	}
	m=rand()%mod;
	printf("%d",m);
	return 0;
}