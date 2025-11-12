#include <bits/stdc++.h>
using namespace std;
//yihuo ^
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,maxn=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		long long ans=0,b=0;
		for(int j=i;j<=n;j++)
		{
		
			
			b^=a[j];
			if(b==k)
			{
				ans++;
				b=0;
			}
//			cout<<b<<" ";
		}
//		cout<<ans<<"\n";
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
