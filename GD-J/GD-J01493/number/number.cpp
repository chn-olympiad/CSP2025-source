#include <bits/stdc++.h>
using namespace std;
int main(){
	freeopen("number.in" ,"r",stdin);
	freeopen("number.out" ,"w",stdout);
	int a,c[10000];
	cin >> a;
	for(int i = 0;i<=a;i++){
		cin >> c[i];
	}
	sort(c + 1,c + a + 1);
	for(int i = 0;i <= a;i++){
		cout << c[i];
	}
	return 0;
}
