#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=998244353;
int n,a[5005];
ll ans;
void dfs(int i,int s,int k,int num){
	if(i==n+1){
		if(num<=2)return;
		if(s<=k*2)return;
		ans++;
		ans%=MOD;
		return; 
	}
	dfs(i+1,s+a[i],a[i],num+1);
	dfs(i+1,s,k,num);
}
ll fastpow(int a,int k){
	if(k==0)return 1;
	if(k==1)return n;
	ll res=fastpow(a,k/2);
	res*=res;
	res%=MOD;
	if(k%2==1)res*=a;
	res%=MOD;
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}else{
		cout<<(fastpow(2,n)-1-((1ll*n)%MOD)-((1ll*n*(n-1)/2)%MOD)+MOD*2)%MOD;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
