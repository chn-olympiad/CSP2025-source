#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110];
ll b[19][19];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll zq=a[1];
	sort(a+1,a+(n*m)+1,cmp);
//	for(ll i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}	
	ll zs=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			zs++;
			if(i%2!=0){
				b[j][i]=a[zs];
			}
			else{
				if(j==m){
					b[j][i]=a[n*(i-1)+1];
				}
				else b[j][i]=a[n*i-(zs%n-1)];
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(b[j][i]==zq){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}