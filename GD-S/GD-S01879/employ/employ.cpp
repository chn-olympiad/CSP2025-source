#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	}
	if(m>n){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans%998244353;
	return 0;
} 
