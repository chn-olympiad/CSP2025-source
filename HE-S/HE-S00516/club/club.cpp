#include<bits/stdc++.h>
using namespace std;
int aa[20020], bb[20020], cc[20020];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i <= 20020; i++){
			aa[i] = 0;
			bb[i] = 0;
			cc[i] = 0;
		}
		long long sum = 0;
		int n;
		cin >> n;
		int a = 0, b = 0, c = 0;
//		if(n == 2){
//			
//		}
		for(int i = 1; i <= n; i++){
			int x1, x2, x3;
			cin >> x1 >> x2 >> x3;
			int first = max(x1, max(x2, x3));
			int second = x1 + x2 + x3 - first - min(x1, min(x2, x3));
			sum += first;
//			cout << "sum "<< sum <<endl;
			if(first == x1){
				a++;
				aa[first - second]++;
			}else if(first == x2){
				b++;
				bb[first - second]++;
			}else if(first == x3){
				c++;
				cc[first - second]++;
			}
		}
		if(a > (n / 2)){
			int w = a - n / 2;
			for(int i = 0; i <= 20020; i++){
				if(aa[i] != 0){
					if(w <= aa[i]){
						sum -= i * w;
						aa[i] -= w;
						w = 0;
						break;
					}else{
						sum -= aa[i] * i;
						w -= aa[i];
						aa[i] = 0;
					}
				}
			}
		}else if(b > (n / 2)){
			int w = b - n / 2;
			for(int i = 0; i <= 20020; i++){
				if(bb[i] != 0){
					if(w <= bb[i]){
						sum -= i * w;
						bb[i] -= w;
						w = 0;
						break;
					}else{
						sum -= bb[i] * i;
						w -= bb[i];
						bb[i] = 0;
					}
				}
			}
		}else if(c > (n / 2)){
			int w = c - n / 2;
			for(int i = 0; i <= 20020; i++){
				if(cc[i] != 0){
					if(w <= cc[i]){
						sum -= i * w;
						cc[i] -= w;
						w = 0;
//						cout << i * w << " o " << sum <<endl;
						break;
					}else{
						sum -= cc[i] * i;
//						cout << i * cc[i] << " v " << sum <<endl;
						w -= cc[i];
						cc[i] = 0;
//						cout << w <<endl <<endl;
					}
				}
			}
		}
//		cout << a << " " << b << " " << c <<endl;
		cout << sum <<endl;
	}
	return 0;
}
