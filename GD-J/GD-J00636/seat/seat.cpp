#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,r;
struct E{
	ll a;
	bool id=0;
} x[200];
bool cmp(E p,E q){
	return p.a>q.a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x[1].id=1;
	for(ll i=1;i<=n*m;i++){
		cin>>x[i].a;
	}
	sort(x+1,x+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(x[i].id){
			c=(i-1)/n+1;
			if(c%2==1) r=i-(c-1)*n;
			else r=n-(i-(c-1)*n)+1;
			cout<<c<<" "<<r;
		}
	}
	return 0;
}
