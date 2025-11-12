#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=10+5;
ll n,m,x;
ll a[N*N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll cnt=0;
	for(ll j=1;j<=m;j++){
		if(j&1){
			for(ll i=1;i<=n;i++){
				cnt++;
				if(a[cnt]==x){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(ll i=n;i>=1;i--){
				cnt++;
				if(a[cnt]==x){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/