#include<bits/stdc++.h>
using namespace std;

string s;
int b[1000005];
int t = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> s;
	
	for(int i = 0;i <= s.length();i++){
		char a = s[i];
		if(a == 48){
			b[t] = 0;
			t++;
		}else if(a == 49){
			b[t] = 1;
			t++;
		}else if(a == 50){
			b[t] = 2;
			t++;
		}else if(a == 51){
			b[t] = 3;
			t++;
		}else if(a == 52){
			b[t] = 4;
			t++;
		}else if(a == 53){
			b[t] = 5;
			t++;
		}else if(a == 54){
			b[t] = 6;
			t++;
		}else if(a == 55){
			b[t] = 7;
			t++;
		}else if(a == 56){
			b[t] = 8;
			t++;
		}else if(a == 57){
			b[t] = 9;
			t++;
		}
	}
	sort(b+0, b+t);
	for(int i = t-1;i >= 0;i--){
		cout << b[i];
	}
	return 0;
} 