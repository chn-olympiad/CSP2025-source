#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, a[101], pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1,a+n*m+1);
	for(int i = n*m;i >= 1;i--){
		if(a[i] == x){
			pos = n*m-i+1;
		}
	}
	if(pos%n==0){
		cout<<pos/n<<" ";
		c = pos / n;
	}
	else{
		cout << pos/n+1<<" ";
		c = pos/n+1;
	}
	if(c % 2 == 1){
		if(pos % n == 0){
			cout << n;
		}
		else{
			cout << pos%n;
		}
	}
	else {
		if(pos % n == 0){
			cout << 1;
		}
		else{
			cout << n - (pos % n) + 1;
		}
	}
	return 0;
}
