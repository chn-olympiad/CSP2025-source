#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,res=1;cin>>n;
	for(int i=1;i<=n;i++){
		res=res*n%998244353; 
	}
	cout<<res;
	return 0;
}

