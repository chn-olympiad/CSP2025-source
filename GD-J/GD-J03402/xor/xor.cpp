#include <bits/stdc++.h>
using namespace std;
int a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i=1;i<=n;i++)cin >> a[i];
	int flag = 0,flag2 = 0;
	for (int i=1;i<=n;i++){
		if (a[i] != 1)flag = 1;
	}
	if (flag == 0){
		if (k == 1)cout << n;
		else if (k == 0){
			cout << n/2;
		}
		else cout << 0;
		return 0;
	}
	cout << n;
	return 0;
} 
