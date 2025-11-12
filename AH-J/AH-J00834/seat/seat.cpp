#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100+10];
bool cmp(const ll &x,const ll &y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i];
	ll r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1,i1=1;i<=m;i++){
		if(i%2){
			for(ll j=1;j<=n;j++){
				if(a[i1++]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(ll j=n;j>=1;j--){
				if(a[i1++]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
