#include <bits/stdc++.h> 
#include <string>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w",stdout);
	string a;
	cin >> a;
	string b;
	int num = 0;
	for (int i = 0; i < a.length(); i++){
		if (a[i] >= '0' && a[i] <= '9'){
		    	b += a[i];
			}
		}
	cout << b;
	return 0;
}
