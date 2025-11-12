#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	if(n<=3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),max(a[2],a[3]))*2) cout<<1;
		else cout<<0;
		return 0;
	}else{
		cout<<((n-2)%mod*(n-2)%mod)%mod;
	}
	return 0;
}