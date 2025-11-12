#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105][105],s[105],b[105][105],cnt;
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,f;
	cin >> n >> m;
	for(ll i = 1;i <= n*m;i++){
		cin >> s[i];
		if(i==1) f = s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(ll i = 1;i <= m;i++){
		if(i%2!=0){
			for(ll j = 1;j <= n;j++){
				a[i][j] = s[++cnt];
			}
		}
		else{
			for(ll j = n;j >=1;j--){
				a[i][j] = s[++cnt];
			}
		}
	}
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			if(a[i][j]==f){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
