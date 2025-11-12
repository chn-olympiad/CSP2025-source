#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll fac(ll n){
	if(n == 0){
		return 1;
	}
	return (n*fac(n-1))%998244353;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;cin>>n;
	cout << fac(n);
	
	fclose(stdin);
	fclose(stdout);return 0;
}
