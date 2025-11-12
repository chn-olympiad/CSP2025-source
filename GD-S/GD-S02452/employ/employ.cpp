#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e2+10;
const int MOD=998244353;
int n,m;
char a[MAXN];
int c[MAXN];
long long By[MAXN];
long long quick_pow(long long a,long long b)
{
	if(b==0) return 1;
	else{
		if(b&1) return quick_pow(a,b-1)*a%MOD;
		else{
			long long t=quick_pow(a,b/2);
			return t*t%MOD;
		}
	}
}
void init()
{
	By[0]=1;
	for(int i=1;i<=n;i++)
	{
		By[i]=By[i-1]*i%MOD;
	}
	return ;
}
long long calc(long long a,long long b)
{
	return By[a]*quick_pow(By[b],MOD-2)%MOD*quick_pow(By[a-b],MOD-2);
}
int num;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("%lld",calc(n,m));
	return 0;
}
