#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
using namespace std;
#define int long long
const int N = 5e5 + 6;
struct node{
	int l,r;
	friend bool operator < (node x,node y){
		if(x.l != y.l) return x.l < y.l;
		else return x.r < y.r;
	}
}tmp[N];
void solve(){
	int n,k,ans = 0,tot = 0;
	cin >> n >> k;
	vector<int> a(n + 1),s(n + 1),id(n + 1);
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1;i <= n; i++)
		s[i] = s[i - 1] ^ a[i],id[i] = i;
//	for(int i = 1;i <= n; i++)
//		if(s[i] == k)
//			ans++;
	int sum = 0;
	for(int i = 1;i <= n; i++){
		sum ^= a[i];
		if(sum == k){
			sum = 0;
			ans++;
		}
	}
	cout << ans;
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("xor5.in","r",stdin),freopen("xor.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
	return 0;
} 
