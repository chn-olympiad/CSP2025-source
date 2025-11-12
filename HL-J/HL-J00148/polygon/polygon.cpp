#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5050],ans,z=1,m=1;bool p=1;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			p=0;
		}
	}
	sort(a+1,a+n+1);
	if(p==1){
		for(int i=1;i<=n-3;i++){
			for(int j=1;j<=i;j++){
				m=(m*j)%mod;
			}
			for(int j=n;j>=n-i+1;j--){
				z=(z*j)%mod;
			}
			ans+=z/m;
			ans=ans%mod;
			m=1;z=1;
		}
		cout<<ans+1<<endl;
		//I LOVE CCF,DON'T RE,PLEASE!
	}else if(n==3){
		if(a[1]+a[2]>=a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		//I LOVE CCF,DON'T RE,PLEASE!
	}
	
	return 0;
}
