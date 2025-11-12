#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
int a[N], b[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[i] = b[i-1] + a[i];
	}
	sort(a+1, a+n+1);
	ll fa = 0;
	if(n == 3){
		ll mx = 0;
		mx = a[n];
		ll h = 0;
		h = b[n] - b[0];
		if(h > mx*2){
			cout << "1";
		}else cout << "0";
	}else if(n < 3) cout << "0";
	return 0;
}
