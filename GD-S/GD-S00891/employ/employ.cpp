#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
const long long mod=998144353;
long long n,m,cnt,ans;
char s[510];
long long c[510];
long long jc[510];
bool nz=true,ao=true;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",c+i);
		if(c[i]==0) nz=false;
	}
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		if(s[i]!='1') ao=false;
	}
	if(n==m&&nz&&ao) printf("%lld",jc[n]);
	else if(n==m) printf("0");
	return 0;
}
