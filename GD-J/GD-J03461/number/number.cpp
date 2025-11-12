#include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin >> t;
	int a[10] = {0};
	for (int i = 0; i < t.length(); i++){
		int n = int(t[i]) - 48;
		if (n >= 0 && n <= 9){
			a[n]++;
		}
	}
	for (int i = 9; i >= 0; i--){
		for (int j = 0; j < a[i]; j++){
			cout << i;
		}
	}
	//fclose("number.in");
	//fclose("number.out");
	return 0;
} 
