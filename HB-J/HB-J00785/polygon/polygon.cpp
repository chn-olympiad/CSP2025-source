#include<bits/stdc++.h>
using namespace std;

int n,a[5005];
long long ans;
const int mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		int x=a[1]+a[2]+a[3];
		if(x>2*a[3]) cout<<1;
		else cout<<0;
	}else{
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			for(int j=1;j<=i;j++){
				x*=n-j+1;
				x%=mod;
				y*=j;
				y%=mod;
			}
			ans+=(x%mod/y%mod)%mod;
		}
		cout<<ans;
	}
	
	return 0;
}
