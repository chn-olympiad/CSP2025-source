#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[501];
int jie(int x){
	if(x==1){
		return 1;
	}
	return (x)*(jie(x-1)%mod)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<jie(n)%mod;
	return 0;
}
