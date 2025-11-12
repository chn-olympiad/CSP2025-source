#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5, MX = 2e6;
int n, k, a[N], qz[N], jl[MX], lst, ans;
bool pd[MX];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	jl[0] = 0, pd[0] = 1;
	for(int i = 1;i <= n;i++){
		qz[i] = qz[i - 1] ^ a[i];
		if(pd[qz[i] ^ k] && jl[qz[i] ^ k] >= lst) ans++, lst = i;
		jl[qz[i]] = i, pd[qz[i]] = 1;
	}
	cout << ans;
	return 0;
}
