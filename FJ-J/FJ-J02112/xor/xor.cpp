#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=2)
		if(k==0)
			printf("%lld",n/2);
	if(k==0)
	{
		int cnt1=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i+1])
				cnt1++,i++;
		printf("%d",cnt1);
	}
	if(k==1)
	{
		int cnt1=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=a[i+1])
				cnt1++,i++;
		printf("%d",cnt1);
	}
	return 0;
}
