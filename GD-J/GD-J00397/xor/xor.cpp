#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,cnt,a[500010];
void solve(){
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans++;
		else cnt++;
	}
	if(k==0) cout<<cnt<<endl;
	else cout<<ans<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
