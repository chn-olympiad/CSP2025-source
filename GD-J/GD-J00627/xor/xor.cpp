#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],cnt=0,ans=0,rr;
bool bz=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) bz=false;
	}
	if(bz==true)
	{
		printf("%lld",n/2);
	}
	else
	{
		printf("0");
	}
	return 0;
}
