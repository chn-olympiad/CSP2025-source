#include<bits/stdc++.h>
#define N 501
#define M 50001
#define mod 998244353
using namespace std;
int pre[N],a[N];
long long g[N][M],g2[5001][5001];
long long fast_pow(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	long long tmp=fast_pow(a,b/2);
	if(b&1)return tmp*tmp%mod*a%mod;
	return tmp*tmp%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	if(n<=500){
		g[2][a[1]+a[2]]++;
		long long ans=0;
		for(int i=3;i<=n;i++){
			for(int k=i;k>=3;k--){
				for(int j=1;j<=pre[i-1];j++)g[k][j+a[i]]=(g[k][j+a[i]]+g[k-1][j])%mod;
				for(int j=a[i]+1;j<=pre[i-1];j++)ans=(ans+g[k-1][j])%mod;
			}
			for(int j=1;j<i;j++)g[2][a[i]+a[j]]=(g[2][a[i]+a[j]]+1)%mod;
		}
		cout<<ans;
	}else if(a[n]==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+fast_pow(2,i-1)-i+mod)%mod;
		}
		cout<<ans;
	}else{
		g2[2][a[1]+a[2]]++;
		long long ans=0;
		for(int i=3;i<=n;i++){
			for(int k=i;k>=3;k--){
				for(int j=1;j<=pre[i-1];j++)g2[k][j+a[i]]=(g2[k][j+a[i]]+g2[k-1][j])%mod;
				for(int j=a[i]+1;j<=pre[i-1];j++)ans=(ans+g2[k-1][j])%mod;
			}
			for(int j=1;j<i;j++)g2[2][a[i]+a[j]]=(g2[2][a[i]+a[j]]+1)%mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}