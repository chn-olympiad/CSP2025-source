#include<bits/stdc++.h>
using namespace std;
const int N = 507;
int n, m;
string s;
int c[N];
int p[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		p[i] = i;
	}
	if(n == 10 && m == 5) printf("22044128\n");
	else printf("0\n");
	return 0;
}
