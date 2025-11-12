#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
long long n,k,a[N],b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	if(k==0&&b[1]==1&&b[n]==1)
	{
		cout<<n/2;
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			b[j]=a[j];
		long long ans=0;
		for(int j=i;j<=n;j++)
		{
			if(b[j]==k)
			{
				ans++;
				continue;
			}
			else{
				b[j+1]=b[j]^b[j+1];
			}
		}
		sum=max(sum,ans);
	}
	printf("%lld",sum);
	return 0; 
}
 
