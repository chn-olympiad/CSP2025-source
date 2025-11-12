#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5, M = 2e6;
int f[N], mp[M];
int n, k, a[N];
int s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		s[i] = s[i-1] ^ a[i];
	}
	memset(mp, -1, sizeof mp);
	mp[k] = 0;
	for(int i = 1;i <= n;i++){
		f[i] = f[i-1];
		f[i] = max(f[i], mp[s[i]] + 1);
		mp[k ^ s[i]] = max(mp[k ^ s[i]], f[i]);
	}
	cout<<f[n];
	return 0;
}

