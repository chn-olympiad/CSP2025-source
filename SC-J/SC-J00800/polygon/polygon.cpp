#include<bits/stdc++.h>
using namespace std;
const int N=5e3+9,MOD=998244353;
long long n,a[N],mx,ans;
/*long long qpow(long long x,long long y){
	long long res=0,k=1;
	while(y>0){
		if(y&1)res+=k%MOD;
		k*=x;
		y>>=1;
	}
	return res;
}*/
void dfs(long long x,long long mx,long long cnt,long long k){
	if(x>n){
		if(cnt>mx*2&&k>=3)ans++;
		return;
	}
	dfs(x+1,max(mx,a[x]),cnt+a[x],k+1);
	dfs(x+1,mx,cnt,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}//
	if(mx==1&&n>20){
		for(int i=3;i<=n;i++){
			long long res=1;
			for(int j=n;j>=i+1;j--)res=res*j%MOD;
			for(int j=1;j<=n-i;j++)res=res/j;
			ans=(ans+res)%MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}