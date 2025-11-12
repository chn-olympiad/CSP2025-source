#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin >> n >> k;
	int tmax = -1;
	int tmin = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tmax = max(a[i],tmax);
		tmin = min(a[i],tmin);
	}
	if(tmin == tmax && tmax == 1){
		cout << n / 2 << endl;
		return 0;
	}
	if(tmax <= 1){
		long long ans = 0;
		if(k == 0){
			for(int i = 1; i <= n; i++){
				if(a[i] == 0){
					ans++;
				}
				if(a[i] == 1 && a[i + 1] == 1){
					i++;
					ans++;
				}
			}
		}else if(k == 1){
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

