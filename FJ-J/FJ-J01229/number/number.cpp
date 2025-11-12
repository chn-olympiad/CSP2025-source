#include<bits/stdc++.h>
using namespace std;

int a[10000000+10];
char s;
int n=1;
int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(cin >> s) {
		if(s == '1' || s == '2' || s == '3' || s == '4' || s == '5' 
		|| s == '6' || s == '7' || s == '8' || s == '9' || s == '0') 
		{
			a[n] = s - '0';
			n ++;
		}
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = n; i > 1; i --) {
		cout << a[i];
	}
	
	cout << endl;
	
	return 0;
}
