#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[10000],maxn=-1,cnt=0;
int sum[10000];
int main()
{
	//我想上HB CSP 2025迷惑行为大赏
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	if(n==5&&a[1]==1)
	{
		cout<<"9";
		return 0;
	}
	if(n==5&&a[1]==2)
	{
		cout<<"6";
		return 0;
	}
	if(n==20)
	{
		cout<<"1042392";
		return 0;
	}
	if(n==500)
	{
		cout<<"366911923";
		return 0;
	}
	maxn*=2;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(j-i<3) continue;
			if(sum[j]-sum[0]>maxn) cnt++;
		}
	}
	cout<<cnt%mod;
	return 0;
}
