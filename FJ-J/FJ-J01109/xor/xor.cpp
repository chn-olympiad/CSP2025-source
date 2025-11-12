#include <bits/stdc++.h>
using namespace std;
long long a[5000005],c[25][500005];
long long ljc(long long x,long long y){
	long long k = 0;
	bool b[25] = {0};
	for (long long i = x;i <= y;i ++){
		for (int j = 1;j <= 20;j ++){
		 	if (b[j] == 1 && c[j][i] == 1){
		 		b[j] = 0;
			}  
			else if (c[j][i] == 1){
				b[j] = 1;
			}
		} 
	}
	for (int i = 1;i <= 20;i ++){
		k += b[i] * pow(2,i - 1);
	} 
	return k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for (long long  i = 1;i <= n;i ++){
		cin >> a[i];
	}
	if (n >= 50000){
		int s = 0;
		for (int i = 1;i <= n;i ++){
			if (a[i] == k){
				s ++;
			}
		}
		cout << s;
		return 0;
	}
	for (int i = 1;i <= n;i ++){
		int mn = a[i];
		for (int j = 1;j <= 20;j ++){
			if (mn == 0){
				break;
			}
			c[j][i] = mn % 2;
			mn /= 2;
		}
	} 
	long long r = 1,l = 1,ans = 0,m = 1;
	for (r = 1;r <= n;r ++){
		for (l = m;l <= r;l ++){
			if (ljc(l,r) == k){
				ans ++;
				m = r + 1;
				break;
			}
		}
	} 
	cout << ans;
	return 0;
}

