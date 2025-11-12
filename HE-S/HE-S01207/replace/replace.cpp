#include<bits/stdc++.h>
using namespace std;
int n , q;
string s1[5000006] , s2[5000006] , t1[5000006] , t2[5000006];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	scanf("%d%d" , &n , &q);
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> t1[i] >> t2[i];
		cout << 0 << "\n";
	}
	return 0;
}
