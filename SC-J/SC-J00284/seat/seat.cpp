#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll b=a[1];
	sort(a+1,a+n*m+1);
//	for(ll i=1;i<=n*m;i++){
//		cout<<a[i]<<endl;
//	}
	ll cnt=n*m;
	for(ll i=1;i<=n;i++){
		if(i%2==1){
			for(ll j=1;j<=m;j++){
//				cout<<cnt<<endl;
				if(a[cnt]==b){
//					cout<<"!"<<endl;
					cout<<i<<" "<<j;
					return 0;
				}
				cnt--;
			}
		}
		else{
			for(ll j=m;j>=1;j--){
				if(a[cnt]==b){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}