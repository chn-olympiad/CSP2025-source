#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;

ll m,n,a[501];

void solve(){
	ll ans=1;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	ll cnt=0,al=0;
	while(cnt!=m){
		cnt++;
		ans*=cnt;
		ans%=mod;
	}
	cout<<ans<<endl;
}

string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	cin>>s;
	solve();
	return 0;
}
