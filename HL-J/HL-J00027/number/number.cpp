#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	short a[1000000];
	string b;
	cin >>b;
	int c = 0;
	for (int i = 0;i < b.length();i++){
		if (b[i] >= '0' && b[i] <= '9'){
			a[c] = b[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	for (int i = c-1;i >= 0;i--){
		cout << a[i];
	}
	return 0;
}
