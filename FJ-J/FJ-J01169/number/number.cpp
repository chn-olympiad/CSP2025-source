#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s;
	while(cin >> s){
		if(s >= '0'&& s <= '1')
			a[s-'0']++;
		else
			a[s-'1']++;
		}
	cout << s << endl;
	return 0;
}
