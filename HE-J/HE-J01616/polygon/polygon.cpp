#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int n;
int a[6666];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(n==3){
		int he=0;
		int ma=-100;
		for(int i=1;i<=n;i++){
			he+=a[i];
			ma=max(ma,a[i]);
		}
		if(he>ma*2) ans++,ans%=mod;
	}
	else{
		for(int i=3;i<n;i++){
			int ji=1;
			for(int j=0;j<i;j++){
				ji*=(n-j);
			}
			for(int j=1;j<=i;j++){
				ji/=j;
			}
			ans=(ans%mod+ji%mod)%mod;
		}
		ans++,ans%=mod;
	}
	cout<<ans;
	return 0;
}
