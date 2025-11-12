#include <bits/stdc++.h>
using namespace std;
string a[1005];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 0;
	
	for(int i = 0;i <= 1000;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[j] = s[i];
			j++;
		}
	}
	
	sort(a, a+1001);
	
	for(int q = 1000;q >= 0;q--){
		cout << a[q];
	}
	
	return 0;
}
 
