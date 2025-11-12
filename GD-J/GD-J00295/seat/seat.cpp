#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],res;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int r = a[1];
	sort(a+1,a+1+m*n);
	reverse(a+1,a+1+m*n);
	for(int i=1;i<=n*m;i++){
		if(a[i] == r){
			res = i;
			break;
		}
	}
	if(res%n == 0){
		if((res/n)%2 == 1) cout << res/n << " " << n;
		else cout << res/n << " " << 1;
		return 0;
	}
	if((res/n)%2 == 0) cout << res/n+1 << " " << res%n;
	else cout << res/n+1 << " " << n+1-res%n;
	return 0;
}
