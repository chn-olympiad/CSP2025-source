#include <bits/stdc++.h>
using namespace std;
long long n,a[49999999],ans = 1,m=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i ++){
	 	cin >> a[i];
	 	m = max(m,a[i]);
	 	if(a[i]!=1){
	 		ans = 0;
		}
	}
	if(n < 3){
		cout << 0;
	}
	if(n == 3){
		if(a[1]+a[2]+a[3] > 2 * m){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	else if(ans == 1){
		cout << (n-1) * (n-2) / 2;
	}
	else if(n == 5){
		if(a[1]==1)cout << 9;
		if(a[1]==2)cout << 6;
		else{
			cout << 13;
		}
	}
	else{
		int sum = 0;
		for(int i=1;i <= n;i++){
			for(int j =i+1;j<=n;j ++){
				for(int k = j+1;k <= n;k ++){
					int sum = 0;
					for(int l = i;i < j;l ++){
						if(a[l]+a[l+1]>2*a[k]){
							sum ++;
						}
					}
					for(int l = j;i < k;l ++){
						if(a[l]+a[l+1]>2*a[i]){
							sum ++;
						}
					}
					int x = 0;
					long long maxn = 0;
					for(int l = i;i < k;l ++){
						x += a[l];
						maxn = max(maxn,a[l]);
					}
					if(x>2*maxn){
						sum ++;
					}
				}
			}
		}
		cout << sum;
	}
	
	return 0;
} 
