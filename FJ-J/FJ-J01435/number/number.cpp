#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
string s;
int len;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for(int i = 0 ; i <= s.size() - 1 ; i++){
		if(s[i] - 48 >= 0 && s[i] - 48 <= 9){
			a[++len] = s[i] - 48;
		}
	}
	sort(a + 1 , a + len + 1);
	for(int i = len ; i >= 1 ; i--){
		cout << a[i];
	}
//	cout << int('9') << endl;
	return 0;
} 
