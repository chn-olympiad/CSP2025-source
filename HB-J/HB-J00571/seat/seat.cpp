#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,cnt=1;

void _find(ll x,ll y){
	if(!((cnt--)-1)){
		cout<<y<<' '<<x;
		return;
	}
	if(y%2==1){
		if(x==n) _find(x,y+1);
		else return _find(x+1,y);
	}else{
		if(x==1) _find(x,y+1);
		else _find(x-1,y);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll peoples=n*m;
	ll r_seat;
	cin>>r_seat;
	for(int i=1;i<=peoples-1;i++){
		ll seat;
		cin>>seat;
		if(seat>r_seat) cnt++;
	}
	_find(1,1);
	return 0;
}
