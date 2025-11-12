#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110],r,cntn,cntm;
bool cmp(const ll &x,const ll &y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i=1; i<=n*m; i++){
		if(cntm % 2){
			cntn++;
		}
		else{
			cntn--;
		}
		if(cntn > n){
			cntm++;
			cntn = n;
		}
		else if(cntn < 1){
			cntm++;
			cntn = 1;
		}
		if(a[i] == r){
			cout << cntm << " " << cntn;
		}
	}
	return 0;
}
