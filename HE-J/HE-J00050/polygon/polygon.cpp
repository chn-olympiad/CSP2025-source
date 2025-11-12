#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,sum,mx=INT_MIN;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<=3){
		if(sum>mx*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<(n*2-1)%mod;
	}
	return 0;
}
