#include<bits/stdc++.h>
using namespace std;
int t[15];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin >> c){
		if(c=='9'){
			t[9]++;
		}else if(c=='8'){
			t[8]++;
		}else if(c=='7'){
			t[7]++;
		}else if(c=='6'){
		    t[6]++;
		}else if(c=='5'){
			t[5]++;
		}else if(c=='4'){
			t[4]++;
		}else if(c=='3'){
			t[3]++;
		}else if(c=='2'){
			t[2]++;
		}else if(c=='1'){
			t[1]++;
		}else if(c=='0'){
			t[0]++;
		}
	}
	while(t[9]--){
		cout << '9';
	}
	while(t[8]--){
		cout << '8';
	}
	while(t[7]--){
		cout << '7';
	}
	while(t[6]--){
		cout << '6';
	}
	while(t[5]--){
		cout << '5';
	}
	while(t[4]--){
		cout << '4';
	}
	while(t[3]--){
		cout << '3';
	}
	while(t[2]--){
		cout << '2';
	}
	while(t[1]--){
		cout << '1';
	}
	while(t[0]--){
		cout << '0';
	}
	return 0;
}
