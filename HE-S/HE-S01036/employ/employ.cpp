#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353; 
int n,m,a[114514],p = 0;
string s;
ll A(int x){
	ll ans = 1;
	for(int i = 1;i <= x;i++) {
		ans = (ans*i) % mod;
	}
	return ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
//	cout << n << m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int cnt = n;
//	cout << n;
	for(int i = 1;i <= n;i++) {
		if(a[i] == 0)  {
			cnt--;
			p++;
		}
	}
//	cout << cnt << " " << p << endl;
	cout << A(cnt)*A(p)%mod;
	return 0;
}
