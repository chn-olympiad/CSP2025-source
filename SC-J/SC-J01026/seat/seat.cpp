#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000];
ll mp[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,s;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,greater<ll>());
	ll tmp=0;
	for(ll j=1;j<=m;j++){
		if(j%2==1){
			for(ll i=1;i<=n;i++)
				mp[i][j]=a[++tmp];
		}
		else{
			for(ll i=n;i>=1;i--)
				mp[i][j]=a[++tmp];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(mp[i][j]==s){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}