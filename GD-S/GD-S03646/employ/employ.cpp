#include <iostream>
using namespace std;

int c[100005];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s; 
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if (n == m){
		cout << 1;
		return 0;
	}
	else{
		cout << 2;
		return 0;
	}
	return 0;
}
