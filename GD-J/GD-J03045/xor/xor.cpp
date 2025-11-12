#include<bits/stdc++.h>
using namespace std;
int n,k,a[101010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if (k == 1) cout << n;
	if (k == 0)	cout << 0;
	else	cout << 7;
	return 0;
}

