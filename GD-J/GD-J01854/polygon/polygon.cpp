#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ax,cnt,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		ax = max(ax,a[i]);
		cnt += a[i];
	}
	if (cnt > 2 * ax) cout << 1;
	else cout << 0;
	return 0;
}
