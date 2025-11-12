#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005];
	long long cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<(1LL<<n);i++)
	{
		long long sum=0,maxx=-1,m=0;
		for(long long j=0;j<n;j++)
		{
			if((1<<j)&i)
			{
				m++;
				maxx=max(a[j],maxx);
				sum+=a[j];
			}
		}
		if(m>=3&&sum>2*maxx)
		{
			cnt=(cnt+1)%N;
		}
	}
	cout<<cnt%N;
	return 0; 
}
