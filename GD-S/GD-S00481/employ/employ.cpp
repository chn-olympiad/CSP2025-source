#include <bits/stdc++.h>
#define int long long
#define N 105
#define mod 998244353
using namespace std;

int n,m;
int jc(int x){
	int ans = 1;
	for (int i=2;i<=x;++i) ans = (ans * i) % mod;
	return ans % mod;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	cin >> n >> m;
 	cout << jc(n);
 	
 	
 	
 	
 	return 0;
 }
