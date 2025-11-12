#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0;
bool c[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==k)
		{
			ans++;
			c[i]=1;
		}
	}
	int en=0;
	for(int i=1; i<=n; i++)
	{
		if(c[i]==0)
		{
			int enn;
			long long t=i+1,temp=a[i];
			bool f=0;
			while(t<=n)
			{
				if(c[t]==1) break;
				temp=temp^a[t];
				if(temp==k)
				{
					enn=t;
					f=1;
					break;
				}
				t++;
			}
			if(f==0) continue;
			else
			{
				if(i>en) 
				{
					ans++;
					en=enn;
				}
				else
				en=min(enn,en);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
