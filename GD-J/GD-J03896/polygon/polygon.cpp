#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353,NR=5001,AR2=10002;
int a[NR],f[AR2]; //大于等于10001的数可以统一 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,ans=0;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(i=1;i<=n;i++) //枚举最大值
	{
		for(j=a[i]*2+1;j<AR2+a[i];j++) ans=(ans+f[j-a[i]])%mod; //当i=1或2时根本进不来 
		for(j=AR2+a[i]-1;j>=a[i];j--) f[min(AR2-1,j)]=(f[min(AR2-1,j)]+f[j-a[i]])%mod;
	}
	cout<<ans;
	return 0;
}
