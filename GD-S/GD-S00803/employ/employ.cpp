#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int n){
	if(n==1){
		return 1;
	}
	return n*f(n-1)%998244353;
}
int n;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cout<<f(n);
	return 0;
}
