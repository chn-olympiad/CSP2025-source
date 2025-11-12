#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
bool flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		if(x == 0) flag = 1;
		if(x) cnt++;
	}
	if(flag)cout << cnt;
	else cout << (n / 2) * 2;
	return 0;
}
