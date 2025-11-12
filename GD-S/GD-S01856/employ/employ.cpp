#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int mod = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;	cin>>n;
	long long s = 1;
	for(int i = 1;i <= n;i++)
		s = (s * i) % mod;
	cout<<s;
	return 0;
}

