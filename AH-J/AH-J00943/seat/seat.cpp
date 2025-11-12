#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=110;
ll r,c,a[N],q[10][10],len;
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>r>>c;//r=2 c=2
	ll n=r*c;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll k=a[1];
	sort(a+1,a+n+1,cmp);
	ll x=1,y=1,dir=2;//s-1 x-2 y-3
	while(len!=n){
		q[x][y]=a[++len];
		if(dir==1){
			x--;
			if(x==1) dir=3;
		}
		else if(dir==2){
			x++;
			if(x==r) dir=3;
		}
		else if(dir==3){
			y++;
			if(y%2) dir=2;
			else dir=1;
		}
	}
	for(ll i=1;i<=r;i++)
		for(ll j=1;j<=c;j++)
			if(q[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}
