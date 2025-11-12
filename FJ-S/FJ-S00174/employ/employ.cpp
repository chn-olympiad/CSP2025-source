#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,ans=1,m,k=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=m;i--){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
}
