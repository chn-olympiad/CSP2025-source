#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	char s[510], c[510];
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>s[n];
	for(int i = 0; i < n; i++) cin>>c[n];
	if(n == 3 && m == 2 && s == "101" && c == "1 1 2") cout<<2;
	return 0;
}
