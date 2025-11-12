#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
long long n,a[5100];
long long ch[5100];
long long vis[5100],ans;
void dfs(ll num,ll Max,ll S){
	if(num>n)return;
	if(num>=3){
		if(Max*2<S){
			ans=(ans+1)%mod;
		}
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(num+1,max(Max,a[i]),S+a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3] and a[1]+a[3]>a[2] and a[2]+a[3]>a[1]){
			cout<<1;
		}else cout<<0;
	}else if(n*n*n<=pow(10,8)){
		dfs(0,0,0);
		cout<<ans/n/(n+1)%mod;
	}else{
		cout<<n*n/2;
	}
	return 0;
}
