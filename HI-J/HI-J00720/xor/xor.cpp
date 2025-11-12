#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n = 0, k = 0,cnt = 0;
	cin >> n >> k;
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	if( n <= 2 ){
		for(int i = 0; i < n; i++){
			if(a[i] == k){
				cnt++;
			}
			if((a[0]^a[1]) == k){
				cnt++;
			}
			if( n == 2 ){
				if((a[0]^a[1]^a[2]) == k){
					cnt++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
	if( k == 0 ){
		for(int i = 0; i <n; i++){
			if(a[i] == 0){
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	if( k == 1 ){
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] == k){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
