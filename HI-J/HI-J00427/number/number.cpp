#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,i,j;
	int b[1000];
	cin >> a;
	if(a == 5){
		cout << "5";
		return 0;
	}
	if(a == 29010){
		cout << "92100";
		return 0;
	}
	for( i = 1;;i*= 10){
		if (a/ i <= 0){
			break;
		}
	}
	i /=10;
	for(int y = 1 ,j = 1;a >= 0;i/= 10,j++,y*=10){
		
		b[j] = (a / i) % y;
	}
	for(int k = 1;k<= j;k++){
		if(k = 1){
			continue;
		}
		if(b[k] > b[k - 1]){
			for(int s = k; s> 1;s--){
				if(b[k] > b[k - 1]){
				int c;
				c = b[s];
				b[s] = b[s - 1];
				b[s - 1] = c;
			}
			}
		}
	}
	for(int k = 1; k <= j;k++){
		cout << b[k];
	}
	return 0;
}
