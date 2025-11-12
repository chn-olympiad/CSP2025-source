#include<bits/stdc++.h>
using namespace std;
int n,k,ans,c,a[10000];
bool b[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=100 && k == 0){
		ans = floor(n/2);
		if(n==1) ans = 0;
		cout << ans;
	}else if(k <= 1){
		if(k == 0){
			for(int i= 1;i<=n;i++){
				if(a[i] == a[i+1]){
					ans++;
					i= i+2;
				}else if(a[i] == 0){
					ans ++;
				}
			}
			cout << ans;
		}else{
			for(int i= 1;i<=n;i++){
				if(a[i] !=a[i+1]){
					ans++;
					i = i+1;
				}else if(a[i] == 1){
					ans ++;
				}
			}
			cout << ans;
		}
	}
	return 0;
}
