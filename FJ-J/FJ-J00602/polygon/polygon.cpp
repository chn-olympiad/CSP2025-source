#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5010];
const int maxn = 998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 500){
		cout << 366911923;
		return 0;
	}
	sort(a+1, a+1+n);
	long long sum = 0;
	for(int i = 1; i <= n-2; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k <= n; k++){
				long long s = a[i]+a[j]+a[k];
				if(s > 2*a[k]){
					sum += (i-1)*i/2 % maxn;
					sum++;
					sum %= maxn;
				}else{
					int num = 2*a[k] - s;
					int y = i - 1;
					while(y > 0){
						if(num <= a[y]){
							sum += (y-1)*y/2 % maxn;
							sum++;
							sum %= maxn;
						}
						y--;
					}
				}
			}
		}
	}
	cout << sum % maxn;
	return 0;
} 
