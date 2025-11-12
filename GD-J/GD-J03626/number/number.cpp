#include <iostream>
using namespace std;
int main(){
	string  a,b,c;
	cin >> a;
	for(int i =0;i < a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b += a[i];
		}
		
	}
	for(int i = 0;i <= 9;i++){
		for(int j = 0;j <b.length();j++){
			if(b[j]== char('9'-i)){
				c += b[j];
			}
			
		}
	}
	cout << c;
}
	
