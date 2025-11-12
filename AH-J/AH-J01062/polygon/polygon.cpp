#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll n;
ll a[N],sum;
bool cmp(ll x,ll y){
	return x>=y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n<3){ cout<<"0"; return 0; }
	if(n>=3){
		if(a[1]+a[2]+a[3]>a[1]*2)	cout<<"1";
		else 	cout<<"0";
		return 0;
	}
	return 0;
}
