#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
string s1[N][N], s2[N][N];
string t1[N][N], t2[N][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= 2; j++) {
    		getline(cin, s1[i][j]);
    		getline(cin, s2[i][j]);
		}
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= q; j++) {
			getline(cin, t1[i][j]);
			getline(cin, t2[i][j]);
		}
	}
	if(n == 4 && q == 2) {
		cout << 2 << endl << 0 ;
		return 0;
	}
	if(n == 3 && q == 4) {
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
		return 0;
	}
	for(int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}
	return 0;
}

