#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,Max=0;
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(Max==1){
		int sum=0;
		for(int i=1;i<=n-2;i++){
			sum=(sum%mod+i%mod)%mod;
		}
		cout<<sum%mod;
	}
	else if(n<=3){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>Max*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
