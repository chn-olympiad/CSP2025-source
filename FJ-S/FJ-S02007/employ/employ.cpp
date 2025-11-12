#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,b,ans=1;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>b;
	}
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans%998244353;
	return 0;
}
