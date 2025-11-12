#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a, ll b){
	if(a>b) return true;
	else return false;
}
ll x, y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a[n*m];
	for(ll i = 1;i <= n*m;i++) cin >> a[i];
	ll r = a[1];
	sort(a,a+n*m+1,cmp);
	for(ll i =1;i <= n*m;i++){
		if(a[i] == r){
			if(i % n == 0) {
				cout << i / n << " ";
				y = i /n;
			}
			else{
				cout << i / n + 1 << " ";
				y = i / n + 1;
			} 
		}
	}
	for(ll i =1;i <= n*m;i++){ 
		if(a[i] == r){
			if(y % 2 == 0){
				cout << n-i%n+1;
			} 
			else{
				if(y % 2 != 0)	{
					if(i % n == 0) cout << i / n+1;
					else cout << i % n;
				}
			}
		}
	}
	return 0;
}

