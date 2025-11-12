#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[n*m+5];
	int min = 1000000;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	} 
	
	int nn = 1;
	int aa[n*m+5];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j] < min){
				min = a[j];
				aa[nn] = a[j];
				nn++;
			}
		}
	}
	int r = 0;
	int c = 0;
	for(int i=1;i<=nn;i++){
		if(aa[i] == a[1]){
			if(i%n == 0){
				c = i%n;
			}else{
				c = i%n+1;
			}
			if(c%2 == 1){
				if(i%n != 0){
					r = i%n;
				}else{
					r = n;
				}
			}else{
				if(i%n != 0){
					r = n - i%n + 1;
				}else{
					r = 1;
				}
			}
		}
	}
	
	cout << r << " " << c << endl;
	
	return 0;
}
