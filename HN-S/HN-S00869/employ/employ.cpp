#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N];
string s;
bool check(){
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()==true){
		int ans=1;
		for(int i=n;i>=1;i--){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
