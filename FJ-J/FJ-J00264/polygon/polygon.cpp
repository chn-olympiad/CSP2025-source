#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],f[N],ans[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)  res=1ll*res*a%mod;
		a=1ll*a*a%mod;b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",a+i);
	sort(a+1,a+1+n);f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=5000;j>=a[i];j--)  f[j]=(f[j]+f[j-a[i]])%mod;
		if(i>=2){
			int sum=0;
			for(int j=0;j<=a[i+1];j++)  sum=(sum+f[j])%mod;
			ans[i+1]=qpow(2,i)-sum;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)  sum=(sum+ans[i])%mod;
	printf("%d",sum);
	return 0;
}
