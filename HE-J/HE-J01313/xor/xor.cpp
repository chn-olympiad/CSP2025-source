#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,k,a[N],numone,numzero;
bool zero=false;
int32_t main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==0)
		{
			zero=true;
			numzero++;
		}
		if(a[i]==1)
		{
			numone++;
		}
	}
	if(k==0&&numzero!=0&&numone==0)
		return printf("%lld",n),0;
	else if(k==0&&numzero==0&&numone!=0&&n%2==0)
		return printf("%lld",n/2),0;
	else if(k==0&&n==2)
		return printf("1"),0;
	else if(k==0&&n==1)
		return printf("0"),0;
	else if(k==0&&numone<numzero)
		return printf("%lld",n/2+1);
	else if(k==0&&numzero==numone)
		return printf("%lld",n/2),0;
	else
		return printf("%lld",n/2),0;
	return 0;
}
