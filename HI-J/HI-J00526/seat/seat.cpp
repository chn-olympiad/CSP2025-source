#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],cnt = 1,aa,c,r;
bool cmp(int x,int y) {
	return x > y;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++) cin>>a[i];
	aa = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++) {
		if(a[i] != aa) cnt++;
		else break;
	}
	int x = cnt;
	if(x % n != 0) c = x/n+1;
	else c = x/n;
	if(cnt % n != 0) {
		r = cnt % n;
		if(c % 2 == 0) r = n-r+1;
	} else {
		r = n;
		if(c % 2 == 0) r = 1;
	}
	cout<<c<<" "<<r;
	return 0;
}
