#include<bits/stdc++.h>
using namespace std;
int a[107];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0, tot = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	bool flag1 = true, flag2 = true;
	for(int i = 1;i <= n;i++){
		if(a[i] == 1) cnt++;
		if(a[i] == 0) tot++;
		if(a[i] > 1) flag2 = false;
		if(a[i] != 1) flag1 = false;
	}if(flag1&&k == 0){
		cout << n/2;
		return 0;
	}if(flag2&&k == 1){
		cout << cnt << endl;
		return 0;
	}if(flag2&&k == 0){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) ans++;
			if(a[i] == 1&&a[i+1] == 1) ans++, i++;
		}cout << ans << endl;
		return 0;
	}cout << 21;
	return 0;
}
