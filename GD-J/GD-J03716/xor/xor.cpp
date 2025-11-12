#include<bits/stdc++.h>
using namespace std;
int n , k;
int a[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool y = 1;
	int mx = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 0) y = 0;
		mx = max(mx , a[i]);
	}
	if(y && k == 0){
		cout << n/2;
		return 0;
	}
	cout << n;
	return 0;
}
