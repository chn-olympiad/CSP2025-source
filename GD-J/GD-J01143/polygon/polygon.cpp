#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[505];
const long long mod=998244353;
long long f[250005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	f[a[1]]=1;
	f[0]=1;
	int he=a[1];
	long long ans=0;
	for(int i=3;i<=n;i++){
		he=he+a[i-1];
		for(int j=he;j>=a[i-1];j--){
			f[j]=(f[j]+f[j-a[i-1]])%mod;
		}
		for(int j=he;j>a[i];j--){
			ans=(ans+f[j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}//I like yuanshen!!!
//di'lu'ke+ro'hua=4w!!!
//liu'lang'zhe+ban'ni'te+yuan'su'zhan'ji=2w!!!
