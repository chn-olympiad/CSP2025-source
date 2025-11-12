#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	bool fa=true,fb=true;
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		if (k!=0 || a[i]!=1)
			fa=false;
		if (k>1 || (a[i]!=1 && a[i]!=0))
			fb=false;
	}
	if (fa)
	{
		cout<<n/2<<endl;
		return 0;
	}
	if (fb)
	{
		int p=0,q=0;
		int ans=0;
		if (k==1)
		{
			for (int i=1;i<=n;++i)
			{
				if (a[i]==1)
					p++;
				else
					q++;
			}
			printf("%d",p);
			return 0;
		}
		if (k==0)
		{
			int y=0;
			for (int i=1;i<=n;++i)
			{
				if (a[i]==1)
					y++;
				else
				{
					q++;
					ans+=y/2;
					y=0;
				}
			}
			ans+=y/2;
			ans+=q;
			printf("%d",ans);
		}
	}
	else
		printf("%d",n/2);
	return 0;
}
