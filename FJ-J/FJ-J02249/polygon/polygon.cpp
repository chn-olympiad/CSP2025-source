#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],f[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0]=f[a[1]]=1;
	int tmp=1,ans=0;
	for(int i=2;i<=n;i++){
		tmp=(tmp<<1)%mod;
		int res=0;
		for(int j=0;j<=a[i];j++)res=(res+f[j])%mod;
		res=(tmp-res+mod)%mod;
		ans=(ans+res)%mod;
		for(int j=5000;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%mod;
	}
	printf("%d",ans);
	return 0;
} 
