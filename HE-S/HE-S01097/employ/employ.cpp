#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int mod = 998244353;	

int n,m,a[N],ans;
string s;

long long qmi (long long a,long long k) {
	
	while (k) {
		
		if (k & 1) a = a * a % mod;
		k >>= 1; 
		a = a % mod;
		
	}
	
	return a;
	
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool f = false;
	
	cin >> n >> m;
	
	cin >> s;
	
	for (int i = 0;i < s.length();i ++) {
		if (s[i] == 1) f = true;
	}
	
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	
	if (!f) {
		int cnt = 0;
		for (int i = 1;i <= n;i ++) {
			if (cnt >= a[i]) cnt ++;
			else ans ++;
		}
		cout << qmi (ans,ans) << '\n';
		return 0;
	}
	
	return 0;
}

