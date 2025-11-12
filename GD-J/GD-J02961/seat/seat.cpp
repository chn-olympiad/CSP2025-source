#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10005][10005],b[50005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> b[i];
	}
	int k = 1;
	for(int i = 1; i <= n * m; i++){
		for(int j = 1; j <= i; j++){
			if(b[i] > b[j]){
				if(j == 1){
					k = i;
				}
				swap(a[i],a[j]);
			}
		}
	}
	
	int c,r;
	if(k % n == 0){
		c = k / n;
		if((k / n) % 2 == 1){
			r = n;
		}else{
			r = 1;
		}
	}else if(k % n == 1){
		c = k / n + 1;
		if((k / n) % 2 == 1){
			r = n;
		}else{
			r = 1;
		}
	}else{
		c = k / n + 1;
		if((k / n) % 2 == 0){
			r = k % n;
		}else{
			r = n - (k % n) + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}
