#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m;
	cin >> n >> m;
	cin >> a[1];
	int x = a[1];
	for(int i = 2;i <= n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n*m+1);
	int ans = 0;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == x){ 
			ans = n*m - i + 1;
			break;
		}	
	}
	int a = ans / n + 1 , b = ans % n;
	if(b == 0){
		b = n;
		a--;
	}else if(a % 2 == 0){
		b = n - b + 1;
	}
	cout << a << " " << b;
	return 0;
}
