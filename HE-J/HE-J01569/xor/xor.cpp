#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int a[N], s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, t = 0 ;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if(a[i] == k) t++;                                              
	}
	cout << t;
	return 0;
}

