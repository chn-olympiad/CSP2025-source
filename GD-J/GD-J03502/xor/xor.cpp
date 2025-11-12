#include<bits/stdc++.h>
using namespace std;
long long a[500001],s[500001],n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	bool bz=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=0&&a[i]!=1) bz=0;
		s[i]=s[i-1]^a[i];
	} 
	if(bz==1&&k==1)
	{
		long long res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) res++;
		}
		cout<<res;
		return 0;
	} 
	if(bz==1&&k==0)
	{
		long long res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) res++;
		}
		cout<<res;
		return 0;
	}
	int p=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=p+1;j<=i;j++)
		{
			long long f=s[i]^s[j-1];
			if(f==k)
			{
				ans++;
				p=i;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}


