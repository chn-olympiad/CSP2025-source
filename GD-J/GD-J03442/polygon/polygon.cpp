#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,c[550][550],a[5500],ans;
void init(){
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++){
		long long u=1;
		for(int k=i+1;k<=j;k++)u=u*k,u%=998244353;
		for(int k=1;k<=j-i;k++)u/=k;
		c[i][j]=u;
	}
}
void dfs(int p,long long sum,long long ma){
	if(p==n+1){
		if(sum>ma*2)ans++,ans%=mod;
		return ;
	}
	dfs(p+1,sum,ma);
	dfs(p+1,sum+a[p],max(ma,a[p]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long o=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),o=max(o,a[i]);
	if(o==1&&n>20){
		init();
		long long sum=0;
		for(int i=3;i<=n;i++)sum=((sum+c[i][n]%mod)+mod)%mod;
		cout<<sum<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
