#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5005];
ll f[5005][5005];
const ll mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	} 
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			printf("1");
		}
		else{
			printf("0");
		}
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)f[i][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=((f[i][j]+f[i-1][j])%mod+f[i-1][j-1])%mod;
		}
	}
	ll ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			printf("f[%d][%d]=%lld\n",i,a[j],f[i][a[j]]);
//		}
//	}
	for(int i=3;i<=n;i++)
	{
		ans=(ans+f[n][i])%mod;
	}
	cout<<ans;
	return 0;
}

