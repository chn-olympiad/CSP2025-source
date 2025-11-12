#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+25;
const ll mod=998244353;
ll n,a[N],C[N][N],dp[N][N],ans,res[N],_2[N];
void init(){
	_2[0]=1;
	for(int i=1;i<=5000;i++){
		_2[i]=_2[i-1]*2;
		_2[i]%=mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	res[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			ans+=_2[i-1];
			for(int j=0;j<=a[i];j++){
				ans=(ans-res[j]+mod)%mod;
			}
		}	
		for(int j=5000;j>=a[i];j--){
			res[j]+=res[j-a[i]];
			res[j]%=mod;
		}
	}
	cout<<ans%mod;
    return 0;
}
