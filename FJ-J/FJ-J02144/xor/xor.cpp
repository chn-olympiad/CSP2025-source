#include <bits/stdc++.h>
using namespace std;

namespace solve{
	// [l, r]
	int get_prefix(const vector<int>& prefix, const int l, const int r){
		return prefix[l-1] ^ prefix[r];
	}
	
	void main(){
		int n, k;
		cin >> n >> k;
		vector<int> prefix(n+1, 0);
		for (int i=0;i<n;i++){
			int ai;
			cin >> ai;
			prefix[i+1] = prefix[i] ^ ai;
		}
//		cout << get_prefix(prefix,2,4) << " " << (1^0^3); // 3 3
		int ans = 0, last_r = 0;
		for (int r=1;r<=n;r++){
			for (int l=r;l>last_r;l--){
				if (get_prefix(prefix, l, r) == k){
					ans++;
					last_r = r;
					break;
				}
			}
		}
		cout << ans;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
