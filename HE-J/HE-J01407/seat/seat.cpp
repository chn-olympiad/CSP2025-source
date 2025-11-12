#include <bits/stdc++.h>
using namespace std;
int n,m,a[114514];
int mrt[114][114];
bool cmp(int a,int b){
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	int si = a[1];
	sort(a+1,a+n*m+1,cmp);
	int l = 1;
	for(int j = 1;j <= m;j++) {
		if(j % 2 == 1) {
			for(int i = 1;i <= n;i++) {
				mrt[i][j] = a[l];
				l++;
			}
		}
		else {
			for(int i = n;i >= 1;i--) {
				mrt[i][j] = a[l];
				l++;
			}			
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(mrt[i][j] == si) {
				cout << j << " " << i;
				break;
			}
		}
	}
	return 0;
}
