#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int ans;
int main(){
	freopen("polygon.in","r",stdout);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				for(int k = j; k <= n; k++){
					if(a[i] < a[j]+a[k] && a[k] < a[i]+a[j] && a[j] < a[i]+a[k]){
						ans++;
					}
				}
			}
		}
	}
	cout << ans; 
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
