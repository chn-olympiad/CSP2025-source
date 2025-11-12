#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ls(u) u << 1ll
#define rs(u) u << 1ll | 1ll
#define mid (l + r >> 1ll)
using namespace std;
const int maxn = 5e5 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1ll);
ll n, k, ans;
ll a[maxn];
ll f[maxn], cnt, cnt2;
bool w1, w2, flag;
ll tim, flag2;
void query(ll u, ll last, ll tot){
	tim ++;
	if(tim >= (ll)1e8){
		flag = 1;
		return;
	}
	
	ans = max(ans, tot);
//	cout << u << " " << last << " " << tot << endl;
	if(u > n){
		return;
	}
	if((f[u] ^ f[last]) == k){
		if((u == last && k == 0 && a[u] == 0) || (u != last)){
//			cout << u  << "{ }" << last << " " << f[u] <<" " << f[last]<< endl;
//			cout << k << " a" << (f[u] ^ f[last]) << endl;
			
			query(u + 1, u, tot + 1);
			if(tim >= (ll)1e8){
				flag = 1;
				return;
			}
		}
	}
	query(u + 1, last, tot);
	if(tim >= (ll)1e8){
		flag = 1;
		return;
	}
	if(u > last){
		query(u, last + 1, tot);
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	cin >> a[1];
	f[1] = a[1];
	if(a[1] == 1) cnt ++;
	
	for(int i = 2;i <= n;i ++){
		cin >> a[i];
		if(a[i] != 1) w1 = 1;
		if(a[i] != 1 && a[i] != 0) w2 = 1;
		if(a[i] == 1) cnt ++;
		f[i] = f[i - 1] ^ (a[i]);
		if(a[i] == k) flag2 ++;
	}
	
	if(w1 == 0){
		if(k != 1ll && k != 0){
			cout << 0;
			return 0;
		}
		if(k == 1ll){
			cout << n;
			return 0;
		}
		if(k == 0){
			cout << n / 2;
			return 0;
		}
		return 0;	
	}
	
	if(w2 == 0){
		if(k != 1 && k != 0){
			cout << 0;
			return 0;
		}
		if(k == 1){
			cout << cnt;
			return 0;
		}
		if(k == 0){
			for(int i = 2;i <= n;i ++){
				if(a[i] == 1 && a[i] == a[i - 1]){
					cnt2 ++;
					i ++; 
				}
			}
			cout << (n - cnt) + cnt2; 
			return 0;
		}
		return 0;
	}
	query(1, 0, 0);
	if(flag == 1){
		if(flag2 > 0 || ans > 0){
			cout << max(ans, flag2);
		}else cout << 0;
	}else cout << ans;
	return 0;
}