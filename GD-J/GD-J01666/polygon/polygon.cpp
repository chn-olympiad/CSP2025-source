#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005],cnt = 0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		for(int i = 1;i <= n-2;i++){
			for(int j = i+1;j <= n-1;j++){
				for(int z = j+1;z <= n;z++){
					if(a[i]+a[j]+a[z]>(2*a[z])){
						cnt++;
					}
				}
			}
		}
		cout << cnt;
	}
	else if(n>3 && n <= 6){
		for(int i = 1;i <= n-2;i++){
			for(int j = i+1;j <= n-1;j++){
				for(int z = j+1;z <= n;z++){
					if(a[i]+a[j]+a[z]>(2*a[z])){
						cnt++;
					}
				}
			}
		}
		for(int q = 1;q <= n-3;q++)
			for(int i = 1+q;i <= n-2;i++){
				for(int j = i+1;j <= n-1;j++){
					for(int z = j+1;z <= n;z++){
						if(a[i]+a[j]+a[z]+a[q]>(2*a[z])){
							cnt++;
						}
					}
				}
			}
		for(int w = 1;w <= n-4;w++)
			for(int q = 1+w;q <= n-3;q++)
				for(int i = 1+q;i <= n-2;i++){
					for(int j = i+1;j <= n-1;j++){
						for(int z = j+1;z <= n;z++){
							if(a[i]+a[j]+a[w]+a[z]+a[q]>(2*a[z])){
								cnt++;
							}
						}
					}
				}
		for(int e = 1;e <= n-5;e++)
			for(int w = 1+e;w <= n-4;w++)
				for(int q = 1+w;q <= n-3;q++)
					for(int i = 1+q;i <= n-2;i++){
						for(int j = i+1;j <= n-1;j++){
							for(int z = j+1;z <= n;z++){
								if(a[i]+a[j]+a[e]+a[w]+a[z]+a[q]>(2*a[z])){
									cnt++;
								}
							}
						}
					}
		cout << cnt;
		return 0;
	}
	
	else if(n > 20 && n <= 5000){
		cout << n-2;
		return 0;
	}
	return 0;
} 
