#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[210],seat[20][20],tot;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll R=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(ll i=1;i<=n;i++){
		if(i%2){
			for(ll j=1;j<=m;j++){
				++tot;
				seat[i][j]=a[tot];
			}
		}
		else{
			for(ll j=m;j>=1;j--){
				++tot;
				seat[i][j]=a[tot];
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(seat[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
