#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	ll n,cnt = 0;
	cin >> n;
	for(ll i = 1;i <=n;i++) cin>>a[i];
	if(n<=2){
		cout << 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cnt++;
		if(a[1]+a[2]>2*max(a[1],a[2])) cnt++;
		if(a[3]+a[2]>2*max(a[3],a[2])) cnt++;
		cout << cnt;
	}
	return 0;
}
