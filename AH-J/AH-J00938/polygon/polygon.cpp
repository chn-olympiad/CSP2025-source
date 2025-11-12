#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const long long MOD=998244353;
unsigned long long n,a[50005],ans=1;
signed main(){
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(min(a[1],min(a[2],a[3]))+max(min(a[1],a[2]),max(min(a[2],a[3]),min(a[1],a[3])))>max(max(a[1],a[2]),a[3]))cout<<1;
		else cout<<0;
		
	}
	else{
		for(int i=3;i<n;i++){
			int p=1;
			for(int j=n-i+1;j<=n;j++)p=p*j%MOD;
			for(int j=2;j<=i;j++)p=p/j%MOD;
			ans=(ans+p)%MOD;
		}
		cout<<ans;
	}
	return 0;
}

