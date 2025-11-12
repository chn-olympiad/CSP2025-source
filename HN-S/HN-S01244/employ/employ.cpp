#include<iostream>
#include<algorithm>
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k=1,mod=998244353;
	cin>>n;
	for(int i=2;i<=n;i++) k*=i,k=(k+mod)%mod;
	cout<<k;
	return 0;
} 
