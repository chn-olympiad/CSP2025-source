#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000000];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int j = 1;
	for(int i = 0; i < a.length(); i++){		
		if(a[i] >= '0' && a[i] <= '9'){
			b[j] = a[i] - 48;
			j++;
		}
	}
    sort(b + 1, b + j + 1);
    for(int i = j; i > 1; i--){
    	cout << b[i];
	}
	return 0;
}