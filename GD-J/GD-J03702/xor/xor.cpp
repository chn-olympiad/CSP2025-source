#include<iostream>
#include<cmath>
using namespace std;

int pf[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(a == 0){
			pf[0] ++;
		} else if(a == 1){
			pf[1] ++;
		} else {
			pf[2] ++;
		}
	}
	if(pf[0] + pf[1] > int(ceil(n * 0.8))){
		cout << 1;
	} else {
		cout << 2;
	} 
	return 0;
}
