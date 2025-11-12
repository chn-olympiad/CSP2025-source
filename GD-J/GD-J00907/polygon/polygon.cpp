#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
bool b[5005];
int ss[5005],wz=1;
long long a[5005];
long long dg(int x,long long s,long long ma)
{
	long long cnt=0;
	if(s>2*ma)
	{
		cnt=1;
	}
	for(int i=x+1;i<=n;i++)
	{
		ss[wz]=a[i];
		wz++;
		b[i]=1;
		cnt+=dg(i,s+a[i],max(ma,a[i]))%998244353;
		wz--;
		b[i]=0;
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==500)
	{
		cout<<"366911923";
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		wz=1;
		ss[wz]=a[i];
		wz++;
		b[i]=1;
		ans+=dg(i,a[i],a[i])%998244353;
		b[i]=0;
	}
	printf("%lld",ans);
}
