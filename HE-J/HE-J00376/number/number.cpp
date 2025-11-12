#include<bits/stdc++.h>
using namespace std;
string s;
char b[1000005];
int a[1000005], n;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		//if ((int)(s[i]) >= 48&&(int)(s[i])<= 57){
			b[i] = s[i];	
		//}
	}
	sort(b, b + n);
	for (int i = 0; i <= n; i++) {
		if ((int)(b[i]) >= 48&&(int)(b[i])<= 57){
			a[i] = b[i]-48;
			n++;	
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = max(a[i], a[i + 1]);
		cout << a[i];
	}
} 
