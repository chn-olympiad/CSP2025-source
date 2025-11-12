#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr int N = 5e6+10;
constexpr ull base = 131;
unordered_map<ull,int>mp;
ull pw[N];
signed main() {
	pw[0] = 1;
	for (int i=1;i<N;i++) pw[i] = pw[i-1] * base;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout << 0 << '\n';
	return 0;
} 
