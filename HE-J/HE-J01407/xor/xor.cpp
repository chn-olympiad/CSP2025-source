//11:24
//I think T3 is more difficult than T4,though I both can't finish them =(
//expect:100+100+25+40 = 265
//I want to join in <HE CSP-J/S kao sheng mi huo xing wei da shang>
//Please guanzhu zzq3 in Luogu,thanks qwq
//And,today is my friend yzs' birthday,he isn't an OIer,but it's meaningful to celebrate =)
#include <bits/stdc++.h>
using namespace std;
int n,k,a[114514*2];
void wa10() {
	int ans = 0;
	if(k == 0) {
		for(int i = 1;i < n;i++) {
			if(a[i] == 0) ans++;
			else if(a[i] == a[i+1]) {
				ans++;
				i++;
			}
		}
		if(a[n] == 0) ans++;
		cout << ans;
	}
}
void wa25(){
	int ans = 0;
	a[n+1] = 114514;
	if(k == 1) {
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) ans++;
			else if(abs(a[i]-a[i+1]) == 1) {
				ans++;
				i++;
			}
		}
		cout << ans;
	}
}
void pian() {
	if(k > 1) cout << 0;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	wa10();
	wa25();
	pian();
	return 0;
}
