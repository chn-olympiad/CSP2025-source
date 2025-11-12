#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n;
	while(n--){
		cout << rand()%3 << '\n';
	}
	return 0;
}
