#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==m){
		long long res=1;
		for(int i=1;i<=n;i++) res=(res*i)%mod;
		cout<<res;
		return 0;
	}
	cout<<0;
}
