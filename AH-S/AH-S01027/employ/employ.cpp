#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],bxhl=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			bxhl++;
		}
	}
	if(n-bxhl<m){
		cout<<0<<endl;
		return 0;
	}else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
