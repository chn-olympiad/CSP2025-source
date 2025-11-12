#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[1010];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ll R;
	cin >> n >> m;
	for(ll i=1;i<=n*m;i++)cin >> a[i];
	R=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	ll rate;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==R){
			rate=i;
			break;
		}
	}
	//cout << rate;
	ll c,r;
	c=ceil(rate*1.0/n);
	cout << c << " ";
	ll yu=rate%n;
	if(c%2==1){
		r=yu;
	}
	if(c%2==0){
		r=n+1-yu;
	}
	if(yu==0){
		if(c%2==1)r=n;
		if(c%2==0)r=1; 
	}
	cout << r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
