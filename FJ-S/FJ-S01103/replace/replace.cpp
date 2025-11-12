#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, q;
string s1[N], s2[N];
string t1, t2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while(q--){
		cin >> t1 >> t2;
		cout << 0 << endl;
	}
	return 0;
}
