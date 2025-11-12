#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ans = 0;
	cin >> s;
	int wei = 1,zhi = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] == '0'){
			a[wei] = 0;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '1'){
			a[wei] = 1;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '2'){
			a[wei] = 2;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '3'){
			a[wei] = 3;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '4'){
			a[wei] = 4;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '5'){
			a[wei] = 5;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '6'){
			a[wei] = 6;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '7'){
			a[wei] = 7;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '8'){
			a[wei] = 8;
			if(i != s.size()-1){
				wei++;
			}
		}else if(s[i] == '9'){
			a[wei] = 9;
			if(i != s.size()-1){
				wei++;
			}
		}
	}	

	int dawei = 0;
	int w = wei;
	for(int j = 1;j <= wei;j++){
		int da = 0;
		for(int i = 1;i <= w;i++){
			if(a[i] > da){
				da = a[i];
				dawei = i;
			}
		}
		for(int m = dawei;m <= w;m++){
			a[m] = a[m + 1];
		}
		
		zhi++;
		b[zhi] = da;
		w--; 
		
	}
	int lingshu = 0;
	for(int i = 1;i <= zhi;i++){
		if(b[i] == 0){
			lingshu ++;
		}
	}
	if(lingshu == wei){
		cout << 0;
	}else{
		for(int i = 1;i <= zhi;i++){
			cout << b[i];
		}
	}
	


	return 0;
}