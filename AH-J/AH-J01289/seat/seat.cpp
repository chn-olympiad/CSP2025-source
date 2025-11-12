#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005];
bool cmp(const ll &x,const ll &y){return x>y;}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	ll xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	ll ansl,ansh;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==xr){
			ansl=ceil(i/n);
			if(i%2==1){
				for(ll j=1;j<=m;j++)
					if(a[j]==xr){ansh=j;break;}
			}
			else{
				for(ll j=m;j>=1;j--)
					if(a[j]==xr){ansh=j;break;}
			}
		}
	}
	cout<<ansl<<" "<<ansh;
	return 0;
}
