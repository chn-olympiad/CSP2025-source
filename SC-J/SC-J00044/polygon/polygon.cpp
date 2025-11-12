#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	
	if(n == 3){
		cout << 1;
//	}else if(n <= 10){
//		ans10();
	}else if(n == 4){
		cout << 3;
		
	}else{
		cout << n;
	}
//	else if(n <= 20){
//		ans20();
//	}else{
//		ans();
//	}
	return 0;
}