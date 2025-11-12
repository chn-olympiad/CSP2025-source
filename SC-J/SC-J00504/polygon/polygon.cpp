#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];long long f[5010][10010];
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int maxN=0;
	for(int i=1;i <= n;i++){
		scanf("%d",&a[i]);
		maxN=max(maxN,2*a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;i <= maxN;i++) f[0][i]=1;
	for(int i=1;i <= n;i++){
		for(int j=0;j <= maxN;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i]){
				f[i][j]+=f[i-1][j-a[i]];
				f[i][j]%=mod;
			}
			//cout<<f[i][j]<<' ';
		}
		//puts("");
	}
	long long ans=1;
	for(int i=1;i <= n;i++){
		ans<<=1ll;
		ans%=mod;
	}
	for(int i=1;i <= n;i++){
		ans=((ans-f[i-1][a[i]])%mod+mod)%mod;
		//cout<<ans<<' ';
	}
	cout<<((ans-1)%mod+mod)%mod;
	return 0;
}