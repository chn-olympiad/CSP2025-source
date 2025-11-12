#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 500005;
int a[N];
int n, k;

void solve(){
	
	cin >> n >> k;
	int ans = 0;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	unordered_map<int, int > mp1;
	int now = 0;
	for(int i = 1; i <= n; i ++) {
		
		if(a[i] == k) {
			ans ++;
			now = 0;
			mp1.clear();
		}
		else if(a[i] == 0) continue;
		else {
			now ^= a[i];
			int ned = k ^ now;
			
			
			if(mp1[ned] || now == k) {
				now = 0;
				ans ++ ;
				mp1.clear();
			}
			else 
				mp1[now] = i;
		}
	}
	
	cout << ans <<  endl;
}
signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t= 1;
	while(t--) solve();
	
	
	return 0;
}