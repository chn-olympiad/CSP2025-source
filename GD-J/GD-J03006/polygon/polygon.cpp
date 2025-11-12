#include<bits/stdc++.h>
using namespace std;
const int N=5000,mod=998244353;
int n,ans,a[N+5],f[N+5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=N;j++)
			ans=(ans+f[j])%mod;
		for(int j=N;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<ans;
	return 0;
}
