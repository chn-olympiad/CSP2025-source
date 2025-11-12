#include <iostream>
#include <fstream>

using namespace std;

char c;
int a[11];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(cin>>c){
		if(c >= '0' && c <= '9'){
			a[int(c) - 48]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			cout<<i;
		}
	}
	return 0;
}
