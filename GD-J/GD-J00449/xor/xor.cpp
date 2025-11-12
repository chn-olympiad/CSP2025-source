#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,ans;
long long k;
bool b;
long long a[N],s[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	while(m<=n)
	{
		b=1;
		for(int j=m+1;j<=n;j++)
		{
			if((s[j]^s[m])==k&&j!=m)
			{
				b=0;
				m=j;
				ans++;
				break;
			}
		}
		if(b) m++;
	}
	printf("%d",ans);
	return 0;
}
