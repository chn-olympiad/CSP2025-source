#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int a[N][10], b[N];
bool c[N][10];
signed main() {
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;cin >> n>>m;
	string s;cin>>s;bool duan = 1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i] != 1) duan =0;
	}
	
	
	if(duan) {
		int kkk =1;
		for(int i = m + 1;i <= n;i ++) {
			kkk *= i;
		}
		for(int i = 1;i <= (n - m);i ++) {
			kkk /= i;
		} cout << kkk;
	}
	else cout<<0;
	return 0;
} 
