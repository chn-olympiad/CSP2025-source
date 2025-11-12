#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<(1<<n);i++)
	{
		long long mx=0,x=0,c=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1)))
			{
				mx=max(mx,a[j]);
				x+=a[j],c++;
			}
		}
		if(x>mx*2&&c>=3) s++,s%=mod;
	}
	printf("%lld",s);
	return 0;
}

