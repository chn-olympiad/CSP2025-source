#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 5e5 + 5;
int n, k;
ll arr[maxn], pre[maxn];
ll buk[3 * maxn];
ll f[maxn];
bool vis[3 * maxn];
//首先，我们可以o1获取区间异或和，其次，不同区间，不相交，也就是说，我们可以只考虑断点，由于前面一个断点一定可以构成一个答案为k的区间 
ll cnt(int l, int r){
	if(l == r)return arr[l];
	if(l == 1)return pre[r];
	return pre[r] ^ pre[l - 1];
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cfalse;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	pre[1] = arr[1];
	for(int i = 2; i <= n; i++){
		pre[i] = pre[i - 1] ^ arr[i];
	}
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		if(cnt(i, i) == k)f[i]++;
		else if(vis[k ^ pre[i]])f[i] = max(buk[k ^ pre[i]] + 1, f[i]);
		else if(pre[i] == k)f[i] = max(f[i], (ll)1);
		buk[pre[i]] = max(f[i], buk[pre[i]]);
		vis[pre[i]] = 1;
//		cout << f[i] << ' ';
	}
	cout << f[n];
	return 0;
}
