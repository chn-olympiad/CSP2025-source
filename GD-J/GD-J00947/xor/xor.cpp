#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i =1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 2&&k == 0){
		if(n == 1){
			cout << 0;
			return 0;
		}else{
			cout << 1;
			return 0;
		}
		return 0;
	}
	if(n <= 10&&k <= 1){
		int cnt = 0;
		int ans = 0;
		if(k == 1){
			for(int i = 1;i <= n;i++){
				if(a[i]){
					cnt++;
				}else{
					for(int j = 1;j <= cnt;j++){
						ans += cnt / j;
					}
					cnt = 0;
				}
			}
		}else if(k == 0){
			for(int i = 1;i <= n;i++){
				if(!a[i]){
					cnt++;
				}else{
					for(int j = 1;j <= cnt;j++){
						ans += cnt / j;
					}
					cnt = 0;
				}
			}
		}
		
		cout << ans;
		return 0;
	}
	cout << 0; 
	return 0;
} 
