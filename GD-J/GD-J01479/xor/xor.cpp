#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans;
bool A,B,q,h;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
		if(a[i] != 1) {
			A = 1;
		}
		if(a[i] != 1 && a[i] != 0) {
			B = 1;
		}
	}
	if(!A) {
		cout << n / 2 << endl;
		return 0;//ÐÔÖÊA
	}
	if(!B) {
		if(k == 1) {
			for(int i = 1; i <= n; i++) {
				if(!q && !h) {
					if(a[i] == 1) {
						q = 1;
					} else if(a[i] == 0) {
						h = 1;
					}
				} else if(q) {
					if(a[i] == 0) {
						ans++;
						q = 0;
					}
				} else if(h) {
					if(a[i] == 1) {
						ans++;
						h = 0;
					}
				}
			}
		}else if(k == 0){
			int sum = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					sum++;
				}
			}
			ans = sum / 2;
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
