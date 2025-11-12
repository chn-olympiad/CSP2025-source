#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n , m;
string s;
int c[N];
int p;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; i++)
		cin >> c[i];
	for(int i = 1 ; i <= n ; i++)
		if(s[i] == 1)
			p++;
	if(p < m){
		cout << 0;
		return 0;
	} 
	int c;
	
	return 0;
}
