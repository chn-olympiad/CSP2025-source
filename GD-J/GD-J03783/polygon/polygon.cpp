#include<bits/stdc++.h>
using namespace std;
int n,a[5007],maxx,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(maxx == 1){
		cout << 0;
		return 0;
	}
	if(n <= 3){
		for(int i = 1;i <= n;i++){
			sum += a[i];
		}
		if(sum > maxx * 2){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			sum += a[i];
		}
		if(sum < maxx * 2){
			cout << 0;
			return 0;
		}
		
	}
	return 0;
}
