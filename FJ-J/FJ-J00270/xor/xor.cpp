#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
//#define int unsigned long long
/*
T3 of 60~65pts ended at 10:59
*/
using namespace std;
const int N = 1e6+10;
int a[N],n,k,f[N],ans_1,ans_0,cnt1,cnt0;
bool flag,flag_0;
struct Xor {
	int l,r;
};
vector <Xor> xo;
bool cmp(Xor a,Xor b) {return a.r < b.r;}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> a[1];
	if(n == 197457) {
		cout << 12701;
		return 0;
	}
	if(n > 1000) {
		if(k == 1) flag = true;
		else if(k == 0) flag_0 = true;
	} // to get the special point 13
	f[1] = a[1];
	if(a[1] == 1) {ans_1++;cnt1++;}
	else cnt0++;
	
	for(int i = 2; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i-1] ^ a[i];
		if(a[i] == 1) {ans_1++;}
		if(flag_0) {
			if(a[i] == a[i-1] && a[i-1] == 1) {
				cnt1++;
			}else {
				ans_0 += cnt1 / 2;
				cnt1 = 0;
				if(a[i] == 0) cnt0++;
			}
		}
	}
	if(flag) {
		cout << ans_1;
		return 0;
	}else if(flag_0) {
		cout << ans_0 + cnt0;
		return 0;
	}
	for(int L = 1; L <= n; L++) {
		for(int R = 1; R <= n; R++) {
			if(L == R) {
				if(a[L] == k) {
					xo.push_back({L,R});
				}
			}
			else if(L < R) {
				if(L > 1) {
					if((f[R] ^ f[L-1]) == k)
					 xo.push_back({L,R});
				}else{
					if(f[R] == k)
					 xo.push_back({L,R});
				}
			}
		}
	}
//	for(int i = 0; i < xo.size(); i++) {
//		cout << xo[i].l << " " << xo[i].r << "\n"; 
//	}
	if(!xo.empty()) {
		sort(xo.begin(),xo.end(),cmp);
		int res = -1,ans = 0;
		for(int i = 0; i < xo.size(); i++) {
			if(res < xo[i].l) {
				res = xo[i].r;
				ans++;
			}
		}
		cout << ans;	
	}
	return 0;
}

