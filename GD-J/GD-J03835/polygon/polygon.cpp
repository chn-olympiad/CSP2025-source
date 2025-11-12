#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[5015];
long long f[515][100015],sum,ans,jia;
long long mo=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[j][a[i]+a[j]]++;
			jia++;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>a[j]*2)f[j][i]+=f[j-1][i-a[j]]%mo;
			f[j][i]%=mo;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		ans+=f[n][i]%mo;
		ans%=mo;
	}
	//ans-=jia%mo;
	ans%=mo;
	cout<<ans;
}

