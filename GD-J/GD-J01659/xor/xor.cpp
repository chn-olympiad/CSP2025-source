#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],maxx,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1] xor a[i];
		if(a[i]==m||b[i]==m)
		{
			maxx++;
			l=i+1;
			b[i]=0;
			continue;
		}
		for(int j=l;j<i;j++)
		{
			if(abs(b[i]-b[j])==m)
			{
				maxx++;	
				l=i+1;
				break;
			}
		}

	}
	printf("%lld",maxx);
	
	
	return 0;
}
