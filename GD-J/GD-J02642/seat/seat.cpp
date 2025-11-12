#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,e=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> a >> b >> c;
	for(int i = 2; i <= a * b; i++){
		cin >> d;
		if(d > c){
			e++;
		}
	}
	cout << (e + a - 1) / a << " ";
	if(((e + a - 1) / a) % 2 == 0){
		e %= a;
		if(e == 0){
			e = a;
		}
		cout << a - e + 1;
	}
	else{
		e %= a;
		if(e == 0){
			e = a;
		}
		cout << e;
	}
	return 0;
} 
