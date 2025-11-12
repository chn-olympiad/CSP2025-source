#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
bool cmp(ll x,ll y){
	return x>y;
}ll check(ll x,ll y,ll n,ll m,ll dlt){
	if(x==1&&y==1){
		return 2;
	}
	if(dlt==1){
		if(x==n){
			return 0;
		}
		if(x==1){
			return 2;
		}
	}if(x>=n){
		return 1;
	}
	if(x<=1){
		return 1;
	}
	return dlt;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		ll x;
		cin>>x;
		v.push_back(x);
	}ll dlt=2;
	ll x=1,y=1,r=v[0];
	sort(v.begin(),v.end(),cmp);
	for(ll i=0;i<n*m;i++){
		if(v[i]==r){
			cout<<y<<" "<<x;
			return 0;
		}
		dlt=check(x,y,n,m,dlt);
		if(dlt==0)x--;
		else if(dlt==1)y++;
		else if(dlt==2)x++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
