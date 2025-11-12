#include<iostream>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int ans,t;
int maxn;
void dfs(int sum,int maxn,int p,int cnt){
	t++;
	if(p>n){
		if(cnt>=3&&sum>maxn*2) ans=(ans+1)%mod;
		return;
	}
	//ัก
	dfs(sum+a[p],max(maxn,a[p]),p+1,cnt+1);	
	//ฒปัก 
	dfs(sum,maxn,p+1,cnt);
}
int _pow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		int ans=_pow(2,n)%mod;
		ans=(ans-n+mod)%mod;
		ans=(ans-n*(n-1)/2+mod)%mod;
		ans=(ans-1+mod)%mod;
		cout<<ans%mod;
		return 0;
	}
	ans=0;
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10

5
1 1 1 1 1

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/
