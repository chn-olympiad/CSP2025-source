#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] == m){
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
