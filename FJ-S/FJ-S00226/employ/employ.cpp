#include<bits/stdc++.h>
using namespace std;
int n,m,nx[1000];
long long ans=1;
string tmy;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>tmy;
	for (int i=1;i<=n;i++){
		cin>>nx[i];
	}
	for (int i=n;i>=1;i--){
		ans=(ans*i%998244353)%998244353;
	}
	cout<<ans;
	return 0;
}
