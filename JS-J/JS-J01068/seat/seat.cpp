#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bool bb;
typedef double dd;
typedef string ss;
typedef void vv;
ll a[105][105];
ll b[10005];
bb cmp(ll x,ll y){
	if(x>y){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,x;
	cin>>n>>m>>x;
	b[1]=x;
	for(ll i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	ll c=1,d=1;
	bb f=1;
	for(ll i=1;i<=n*m;i++){
		a[c][d]=b[i];
		if(a[c][d]==x){
			cout<<c<<" "<<d<<endl;
			return 0;
		}
		if (f){
			if(d<n){
				d++;
			}
			else{
				c++;
				f=0;
			}
		}
		else{
			if(d>1){
				d--;
			}
			else{
				c++;
				f=1;
			}
		}
	}

	return 0;
}
