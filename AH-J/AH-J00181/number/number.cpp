#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){

	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	
	int x;
	string s;
	cin >> s;
	
	for (int i = 0;i <= 1000005;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			x = s[i];
			a[x]++;
		}
	}
	
	for (int i = 9;i >= 0;i--){
		while(a[i]>0){
			cout << i;
			a[i]--;
		}	
	}
	
	
	
	return 0;
}
