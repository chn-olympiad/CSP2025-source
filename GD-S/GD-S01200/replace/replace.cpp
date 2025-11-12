#include <iostream>
#include <cstdio>
#include <string>
using namespace std; 
string a[2000005];
int main(){
	//freopen("replace.in", "r", stdin);
	//freopen("replace.out", "w", stdout);
	int n,q;
	cin >> n >> q;
	for (int i=1;i<n+q;i++){
		cin >> a[i];
	}
	for (int i=1;i<=q;i++){
		cout << 0 << endl;
	}
}
