#include<bits/stdc++.h>
using namespace std;
#define int long long
int const F=998244353;
int n;
int const D=5050;
int a[D]; 
long long ans=0;
int hz[D];
void dfs(int x,int sum,int max1){
	if(x==n+1){
		if(sum>2*max1){
			ans=(ans+1)%F;
		}
		return;
	}
	dfs(x+1,sum+a[x],a[x]);
	dfs(x+1,sum,max1);
}
int df(int x){
	if(x!=1)return x*df(x-1);
	else return 1;
}
bool mk=true;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)mk=false;
		hz[i]=hz[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(mk==true){
		int sum=1;
		for(int i=3;i<=n;i++){
			sum+=df(n)/df(i)/df(n-i); 
		}
		cout<<sum;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%F;
	return 0;
}
