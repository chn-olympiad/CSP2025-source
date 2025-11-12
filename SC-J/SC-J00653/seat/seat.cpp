#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			r=n*m-i+1;
			break;
		}
	}
	cout << ceil(r*1.0/n) << " ";
	if(r%n==0){
		if(r/n%2==1) cout << n;
		else cout << 1;
	}
	else{
		if(r/n%2==0) cout << r%n;
		else cout << n-r%n+1;
	}
	return 0;
}