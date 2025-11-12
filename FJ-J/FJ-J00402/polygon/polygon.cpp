#include<bits/stdc++.h>
using namespace std;
int n , a[1000001];
int Max(int l,int r) {
	int ans = -1;
	for(int i = l;i<= r;i++) max(ans,a[i]);
	return ans;
}
int Sum(int l,int r) {
	int ans = 0;
	for(int i = l;i<= r;i++) ans += a[i];
	return ans;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<= n;i++) cin >> a[i];
	long long cnt = 0;
	for(int i = 2;i <= n;i++) {
		for(int j = 1;j+i <= n;j++) {
			if(Sum(a[j],a[j+i]) > 2 * Max(a[j],a[j+i])) {
				cnt %= 998244353;
				cnt++;
			}
		}
	} 
	cout << cnt;
	return 0;
}
