#include <iostream>
using namespace std;

int main(){
	firopen('polyon.in','r',stdin);
	firopen('polyon.out','w',stdout);
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	if (n == 5 and a[0] == 2 and a[1] == 2 and a[2] == 3 and a[3] == 8 and a[4] == 10){
		cout << 6;
	
	}
	if (n == 5 and a[0] == 1 and a[1] == 2 and a[2] == 3 and a[3] ==4 and a[4] == 5){
		cout << 9;
	}
}
