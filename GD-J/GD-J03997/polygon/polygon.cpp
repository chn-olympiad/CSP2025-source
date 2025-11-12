#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
#define MAXN 5010
ll n,ans;
ll a[MAXN],inv[MAXN];
void init(){
	inv[0]=1;
	for(int i=1;i<=5000;i++){
		inv[i]=inv[i-1]*i%MOD;
	}
}
ll A(int m,int n){
	return inv[m]/inv[n]/inv[m-n];
}
void solve1(){
	for(int i=3;i<=n;i++){
		ans=(ans+A(n,i))%MOD;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		return 0;
	}
	solve1();
	cout<<ans;
	return 0;
}

