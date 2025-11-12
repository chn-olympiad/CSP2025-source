#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	vector<int> v(n);
	int s;
	cin >> s;
	for(auto &i:v) cin >> i;
	
	long long ans = 1;
	for(int i=1;i<=n;i++){
		ans = (1ll * ans * i) % mod;
	}
	
	cout << ans << '\n';
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
