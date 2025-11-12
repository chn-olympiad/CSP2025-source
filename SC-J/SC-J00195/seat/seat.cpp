#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,m,a[105],s,x,y;
map<ll,ll> mp;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		mp[a[i]]=i;
	}
	y=mp[s]/n;
	x=mp[s]%n;
	if(x==0){
		if(y%2==1){
			cout<<y<<' '<<n;
		}else{
			cout<<y<<' '<<1;
		}
	}else if(x==1){
		if(y%2==1){
			cout<<y+1<<' '<<n;
		}else{
			cout<<y+1<<' '<<1;
		}
	}
	else{
		if((y+1)%2==1){
			cout<<y+1<<' '<<x;
		}else{
			cout<<y+1<<' '<<n-x+1;
		}
	}
	return 0;
}
/*
3 3
5 1 2 3 4 8 6 7 9
 
*/
