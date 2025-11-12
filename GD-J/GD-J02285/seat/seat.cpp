#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105];
bool s(ll x,ll y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	ll r = a[1];
	sort(a + 1,a + n * m + 1,s);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == r) r = i;
	}
	ll h,l;
	l = r / n;
	if(r % n) l++;
	r %= 2 * n;
	if(r == 0) h = 1;
	else if(r <= n) h = r;
	else h = n + 1 - (r - n);
	cout << l << " " << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
