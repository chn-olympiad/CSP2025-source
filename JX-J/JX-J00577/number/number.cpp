#include <bits/stdc++.h>
using namespace std;
int b[10086], c[10086];
int f(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in","r", stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int len = a.size();
	for(int i = 0; i < len; i++){
        b[i] = a[i];
        if(b[i] - '0' >= 0 && b[i] - '0' <= 9){
            c[i] = b[i];
		}
	}

	sort(c, c + len, f);
	for(int i = 0; i < len; i++){
		if(c[i] - 48 >= 0){
            cout << c[i] - 48;
		}
	}
	return 0;
}
