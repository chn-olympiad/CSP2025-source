#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[505];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]==0)n--;
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout << ans;
	return 0;
}
