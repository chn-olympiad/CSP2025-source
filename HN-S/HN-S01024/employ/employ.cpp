#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[505]; 
string s;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	int ans=1;
	for(int i=1, j=n;i<=m;i++, j--){
		ans*=j;
		ans%=998244353;
	}
	cout << ans;
	return 0;
} 
