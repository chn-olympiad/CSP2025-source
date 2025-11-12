/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int mod = 998244353;
int n,m;
long long a[N],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1,x;i <= n;i++) cin >> x;
	int cnt = n;
	a[1] = 1;
	for(int i = 2;i <= n;i++)
		a[i] = a[i-1] % mod * i % mod;
	for(int i = m;i <= n;i++){
		ans = (ans%mod + a[i]%mod) % mod;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
