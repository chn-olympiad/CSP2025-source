#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	bool flag1 = 1,flag2 = 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i]!=1) flag1 = 0;
		if(a[i]>2) flag2 = 0;
	}
	if(flag1){
		cout << n/2;
		return 0; 
	}
	if(flag2){
		int sum = 0,ans;
		for(int i = 1; i <= n; i ++) sum += a[i];
		if(k) ans = sum;
		else ans = n-sum + sum/2;
		cout << ans;
		return 0;
	}
	return 0;
}

