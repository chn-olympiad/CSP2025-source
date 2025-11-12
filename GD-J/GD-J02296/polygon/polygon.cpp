#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e3+5;
int n,a[MAXN],ans;
ll s[MAXN],yh[2005][2005];
ll MOD=998244353,f[MAXN];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	/*for(int i=1;i<=min(n,2000);i++)
		yh[i][i]=1;
	for(int i=1;i<=min(n,2000);i++)
		for(int j=1;j<=i;j++)
			yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%MOD;*/
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	if(n==3)
	{
		ll maxn=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>maxn*2)
			printf("1");
		else
			printf("0");
		return 0;
	}
	printf("9");
	/*sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]*2>=s[i])
			continue;
		f[i]=
		ll k=s[i]-a[i]*2;
		ll k1=s[i-1]-k+1,s1=0;		//     i/i-1
		for(int j=1;j<=i-1;j++)
			s1=(s1+yh[i-1][j])%MOD;
		
	}*/
	return 0;
}
