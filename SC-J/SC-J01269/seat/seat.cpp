#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans,a[2005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	stable_sort(a+1,a+1+n*m);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==ans){
			ans=n*m-i+1;
			break;
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=n;j++){
			ll tmp=(i-1)*n+j;
			if(i%2==0) tmp=(i-1)*n+(n-j+1);
			if(tmp==ans){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	return 0;
} 