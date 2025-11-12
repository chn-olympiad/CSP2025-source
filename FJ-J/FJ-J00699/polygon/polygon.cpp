#include<bits/stdc++.h>
using namespace std;
int a[5500];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans1=0, maxx=0, flag=0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans1 += a[i];
		maxx = max(maxx,a[i]);
		if(a[i] > 1) flag=1;
	}
	if(n < 3){
		cout << 0;
	}else if(flag == 0){
		cout << n*(n-1);
	}else{
		if(ans1 >= maxx*2) cout << 1;
		else cout << 0; 
	}
	return 0;
}
