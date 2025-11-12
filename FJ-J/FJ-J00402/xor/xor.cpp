#include<bits/stdc++.h>
using namespace std;
int a[500001];
bool b[500001];
int n , k;
bool xorsum(int x,int y) {
	long long qwq = a[x];
	for(int i = x+1;i <= y;i++) {
		qwq ^= a[i];
	}
	return qwq == k;
}
bool chong_he(int x,int y) {
	bool flag = 0;
	for(int i = x;i <= y;i++) {
		if(b[a[i]] != 1) flag = 1;
		if(flag) return 1;
	}
	return flag;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 1;j+i <= n;j++) {
			if(xorsum(j,j+i)) {
				if(chong_he(j,j+i)) {
					cnt++;
					for(int k = j;k <= j+i;k++) {
						b[k]++;
					}
				}
			}
		}
	} 
	cout << cnt;
	return 0;
}
