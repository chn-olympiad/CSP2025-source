#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0 << endl;
		exit(0);
	}
	if(n==3){
		if(a[1]*2>a[2]+a[3]||a[2]*2>a[1]+a[3]||a[3]*2>a[1]+a[2]){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}
