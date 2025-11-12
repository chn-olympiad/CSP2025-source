#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,mx[(1<<20)+5],sum[(1<<20)+5],ans=0,a[5010],f[5010];
int qmi(int a,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1) ret=ret*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return ret;
}
/*long long C(int n,int m)
{
	return (f[n]*qmi(f[m],mod-2))%mod*(qmi(f[n-m],mod-2)%mod;
}*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//int m=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		//m=max(m,a[i]);
	}
	/*f[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	if(mx==1&&n>20)
	{
		for(int i=3;i<=n;i++)
		{
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}*/
	for(int s=0;s<=(1<<n)-1;s++){
		for(int j=0;j<n;j++){
			if(s&(1<<j)) sum[s]+=a[j],mx[s]=max(mx[s],a[j]);
		}
		if(sum[s]>mx[s]*2){
			ans=(ans+1)%mod;
		}
	}
	cout<<ans;
	return 0;
}
