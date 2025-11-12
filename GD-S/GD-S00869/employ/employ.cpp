#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool check(){
	for(char i:s){
		if(i!='1'){
			return false;
		}
	}
	return true;
}
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}



