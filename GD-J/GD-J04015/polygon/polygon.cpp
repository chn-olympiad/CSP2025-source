#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5100];
long long f[5050];
long long ans;
void dfs(int num,int pos,long long sum){
	if(num>n) return;
	if(num>=3&&2*a[pos]<sum) ans++;
	ans%=mod;
	for(int i=pos+1;i<=n;i++)
		dfs(num+1,i,sum+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
//	if(b==0){
//		long long cnt=1;
//		f[0]=1;
//		for(int i=1;i<=n;i++){
//			cnt*=i;
//			f[i]=cnt;
//		}
//		cout<<f[20]<<endl;
//		for(int i=3;i<=n;i++){
//			ans=(ans+f[n]/f[i]/f[n-i])%mod;
//			cout<<ans<<endl;
//		}
//		cout<<ans;
//		return 0;
//	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
