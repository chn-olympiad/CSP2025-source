#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxn=0,res=0;
	cin>>n;
	for(long long i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		long long ans=0;
		ans+=a[i]+a[i+1];
		for(long long j=i+2;j<=n;j++)
		{
			ans+=a[j];
			if(ans>maxn*2) res+=1+(n-j+1);
			continue;
		}
	}
	cout<<res%998244353;
    return 0;
}
//rp++
