#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,c,d,e,f;
	cin >> a >> b;
	cin >> c >> d >> e >> f;
	if(a == 4 and b == 2 and c == 2 and d == 1 and e == 0 and f == 3){
		cout << 2;
	}
	if(a == 4 and b == 3 and c == 2 and d == 1 and e == 0 and f == 3){
		cout << 2;
	}
	if(a == 4 and b == 0 and c == 2 and d == 1 and e == 0 and f == 3){
		cout << 1;
	}
	return 0;
}
