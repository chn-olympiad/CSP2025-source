#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=m;i>=1;i--){
		if(ans<1)ans=1;
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
