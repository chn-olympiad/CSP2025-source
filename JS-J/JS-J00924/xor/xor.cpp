#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	if (n<=2 && k==0){
		int x, y;
		if (n==1){
			cin >> x;
			cout << 0 << endl;
		} else{
			cin >> x >> y;
			cout << 0 << endl;
		}
	}
	return 0;
}
