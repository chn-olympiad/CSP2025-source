#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n;
	cin >> n;
	for (int i= 0;i <= n;i++){
		if (n % 10 == 0){
			n /= 10;
		}
	}
	cout << n;
	
	
	return 0;
} 

