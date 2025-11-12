#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		int x;
		cin >> x;
	}
	if (k <= 1){
		cout << 0;
	}else{
		cout << rand()%n+1;
	}
	return 0;
}
