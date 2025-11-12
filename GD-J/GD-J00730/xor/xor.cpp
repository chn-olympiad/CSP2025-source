#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct pt{
	ll l,r;
};
ll n,k,dp_size,chk_k;
ll a[N];
unordered_map <ll,vector <ll> > mp;
vector <pt> qj;
vector <ll> dp;
bool cmp(pt a1,pt a2){
	if (a1.r != a2.r)return a1.r < a2.r;
	else return a1.l < a2.l;
}
ll lb(ll qjl,ll size){
	if (size == 0)return 1;
	ll l = 1,r = size;
	ll mid = l + ((r - l) >> 1);
	while (l < r){
		if (dp[mid] > qjl){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if (dp[r - 1] >= qjl){
		return r - 1;
	}
	else if (dp[r] < qjl){
		return r + 1;
	}
	else{
		return r;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin >> n >> k;
	for (ll i = 1;i <= n;i++){
		cin >> a[i];
//		cout << a[i] << ' ' << (a[i] ^ a[i - 1]) << ' ';
		a[i] ^= a[i - 1];
		mp[a[i] ^ k].push_back(i);
		if (!chk_k && a[i] == k){
			chk_k = 1;
			qj.push_back(pt({1,i})); 
		}
//		cout << (a[i] ^ k) << ' ' << i << '\n';
	}
//	cout << '\n';
	for (ll i = 1;i <= n;i++){
		ll l = -inf;
		for (ll j = 0;j < mp[a[i]].size();j++){
			if (mp[a[i]][j] < i){
				if (mp[a[i]][j] > l){
					l = mp[a[i]][j];
				}
			}
			else if (mp[a[i]][j] == i){
				l = i;
				break;
			}
		}
		if (l != -inf){
			qj.push_back(pt({l + 1,i}));
		}
	}
	stable_sort(qj.begin(),qj.end(),cmp);
	dp.resize(qj.size() + 5);
	for (int i = 0;i < qj.size();i++){
		ll tar = lb(qj[i].l,dp_size);
		if (tar > dp_size){
			++dp_size;
			dp[tar] = qj[i].r;
		}
		dp[tar] = max(dp[tar],qj[i].r);
//		cout << qj[i].l << ' ' << qj[i].r << '\n';
	}
	cout << dp_size;
//	cout << '\n';
//	for (int i = 1;i <= dp_size;i++){
//		cout << dp[i] << ' ';
//	}
	return 0;
}
