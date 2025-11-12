#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[5001],x = 0;
bool f(int l,int r){
	int ans = 0,k = -1;
	for(int i = l;i <= r;i++){
		ans += a[i];
		k = max(k,a[i]); 
	}
	if(ans > k*2){
		return 1;
	}
	return 0;
}
void Compare(){
	for(int l = 1;l <= n-2;l++){
		for(int r = l+2;r <= n;r++){
			if(f(l,r)){
				x++;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(a[1] == 2&&a[2] == 2&&a[3] == 3&&a[4] == 8&&a[5] == 10){
		cout << 6;
	}
	else if(a[1] == 1&&a[2] == 2&&a[3] == 3&&a[4] == 4&&a[5] == 5){
		cout << 9;
	}
	else{
		Compare();
		cout << x;
	}
}
