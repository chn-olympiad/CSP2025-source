#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+19;
const int N = 1e6+19;

void solve(){
	int n,m,ans = 1;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		ans *= i;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
