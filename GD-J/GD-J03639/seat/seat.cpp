#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct tt{
	ll sz,id;
}a[1000010];
bool cmp(tt a,tt b){
	return a.sz>b.sz;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i].sz,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i].id==1){
			ll l=i/n+(i%n!=0),h=(i-1)%n+1;
			if(l%2==0) h=n-h+1;
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}
