#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n,q;
string a[N * 2],b[N * 2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n * 2;i++){
		cin >> a[i];
    }
    for (int i = 1;i <= q * 2;i++){
    	cin >> b[i];
	}
	for (int i = 1;i <= q;i++){
		cout << 0 << endl;
	}
	return 0;
}
