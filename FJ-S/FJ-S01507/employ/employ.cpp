#include <bits/stdc++.h>
using namespace std;
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){int t; cin >> t; if(t==0) n--;}
	if(n<m) cout << 0;
	for(int i = 1;i <= n;i++){
		ans*=i; ans%=998244353;
	}cout << ans;
	return 0;
}
