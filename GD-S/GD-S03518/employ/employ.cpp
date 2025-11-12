#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;cin>>n;
	long long ans=1;
	for(long long i=2;i<=n;++i){
		ans=(ans*i)%p;
	}
	cout<<ans;
	return 0;	
}
