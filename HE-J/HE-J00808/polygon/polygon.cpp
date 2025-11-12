#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int m=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		int ans=0;
		for(int i=3;i<=n;i++){
			int p=1;
			for(int j=i+1;j<=n;j++){
				p=p*j%mod;
			}
			int q=1;
			for(int j=1;j<=n-i;j++){
				q=q*j%mod;
			}
			ans=(ans+p/q)%mod;
		}
		cout<<ans%mod;
	}
	return 0;
}
