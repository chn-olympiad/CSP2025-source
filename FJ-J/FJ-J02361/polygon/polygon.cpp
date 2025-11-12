#include <bits/stdc++.h>
#define int long long
using namespace std;
string pj;
int n, a[5005], ans = 0, ind = 1, lyh[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607};
string to_binary(int x){
	string res = "";
	while (x > 0){
		res += (x % 2) + '0';
		x /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}
void nextpj(int len){
	if (ind == lyh[len]){
		pj = "over";
		return;
	}
	pj = to_binary(ind);
	ind++;
	
	while (pj.size() < len){
		pj = "0" + pj;
	}
}
bool check(){
	if (pj == "over") return false;
	int sum = 0, maxn = 0;
	for (int i=0; i<n; i++){
		if (pj[i] == '1'){
			sum += a[i+1];
			maxn = max(a[i+1], maxn);
		}
	}
	return sum > 2 * maxn;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	while (pj != "over"){
		nextpj(n);
		if (check()) ans++;
	}
	cout << ans + 1 << "\n";
	return 0;
}
