#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010];
int f[5010],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=5001;j>a[i];j--){
			ans=(ans+f[j])%mod;
		}
		for(int j=5001;j>=0;j--){
			int d=j+a[i];
			if(d>5000)d=5001;
			f[d]=(f[d]+f[j])%mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
