#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5005;
const int Mod=998244353;
int n;
int a[N],pre[N],fac[N];
int dp[N];
int c(int x,int y){
	return (fac[x]%Mod/(fac[y]%Mod*fac[x-y]%Mod))%Mod;
}
void f(){
	fac[0]=1;
	fac[1]=1;
	for(int i=2;i<=5005;i++){
		fac[i]=fac[i-1]*i%Mod;
	}
}
int ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
	sort(a+1,a+1+n);
	if(n==3){
	   if((a[1]+a[2]+a[3])>2*a[3]) cout<<1;
	   else cout<<0;
	   return 0;	
	}
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%Mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
