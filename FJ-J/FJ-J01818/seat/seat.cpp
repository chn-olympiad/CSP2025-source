#include<bits/stdc++.h>

using namespace std;

int n , m;
int x , k; 
int ans = 1;
int p , q;

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	cin >> x;
	k = x;
	for(int i = 2;i <= n * m;i++){
		cin >> x;
		if(x > k){
			ans++;
		}
	}
	p = 1;
	q = 1;
	for(int i = 1;i < ans;i++){
		if(q % 2 == 1){
			p++;
			if(p > n){
				p--;
				q++;
			}
		}else{
			p--;
			if(p <= 0){
				p++;
				q++;
			}			
		}
	}
	cout << q << " " << p <<endl;
	
	return 0;
} 
