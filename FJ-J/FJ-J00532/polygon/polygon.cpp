#include <bits/stdc++.h>
using namespace std;

long long a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	long long cnt=0;
	for(long long i=3;i<=n;i++)//shu liang
	{
		for(long long j=1;j<=n-i+1;j++)//qi dian
		{
			long long maxn=0,ans=0;
			for(long long k=j;k<=j+i-1;k++)
			{
				ans+=a[k];
				maxn=max(maxn,a[k]);
				//cout<<a[k]<<" ";
			}
			if(ans<=2*maxn) continue;
			for(long long k=j;k<=j+i;k++) 
			//cout<<endl;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
