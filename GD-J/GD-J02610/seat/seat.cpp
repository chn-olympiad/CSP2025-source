#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=107;
ll n,m,a[N],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			cnt++;
		}
	}
//	cnt++;
	ll x=cnt/n;
//	cout<<cnt;
	cnt++;
	if(x%2==0){
		cout<<x+1<<' '<<cnt-n*x;
	}else{
		cout<<x+1<<' '<<m-(cnt-n*x)+1;
	}
	return 0;
}
