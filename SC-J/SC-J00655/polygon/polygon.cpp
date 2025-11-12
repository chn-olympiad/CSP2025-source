#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
const long long mod=998244353;
long long a[5010],f[5010];
long long n,ans=0,x;
//long long ksm(long long a,long long b){
//	long long cnt=0;
//	while(b){
//		if(b&1)cnt=(cnt+a)%mod;
//		a=(a*a)%mod;
//		b/=2;
//	}
//	return cnt;
//}
void dfs(long long ii,long long sum,long long t){
	if(ii>n){
		if(t>=2&&sum>2*x){
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(ii+1,sum,t);
	dfs(ii+1,sum+a[ii],t+1);
}
int main(){
	fre("polygon");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long maxx=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
//	if(maxx==1){
//		f[0]=1;
//		for(long long i=1;i<=n;i++){
//			f[i]=f[i-1]*i%mod;
//		}
//		long long res=0;
//		for(long long i=3;i<=n;i++){
//			res+=ksm(f[n],mod-2)*ksm(f[i],mod-2)*ksm(f[n-i],mod-2);
//		}
//		cout<<res;
//	}
	sort(a+1,a+1+n,[&](long long x,long long y){return x>y;});
	for(long long i=1;i<=n-2;i++){
		x=a[i];
		dfs(i+1,x,0);
	}
	cout<<ans;
}