#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef long long ll;
ll a[N],n,m,c[N][N];
bool cmp(ll aa,ll bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll cnt=0,flag=0;
	ll ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll e=1;e<=m;e++){
		flag=(flag+1)%2;
		if(flag==1){
			ll t=0;
			for(ll i=1;i<=n;i++){
				t++;
				cnt++;
				c[e][t]=a[cnt];
			}
		}else{
			ll t=n;
			for(ll i=1;i<=n;i++){
				cnt++;
				c[e][t]=a[cnt];
				t--;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(c[i][j]==ans){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

