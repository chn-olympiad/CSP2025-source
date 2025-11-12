#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,maxn=-1,minn=101;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	ll x=a[1];
	sort(a+1,a+n+1);
	if(x==minn){
		 if(m%2!=0) cout<<n<<" "<<m;
		 else cout<<m<<" "<<1;
	}
	else if(x==maxn){
		 if(m%2!=0) cout<<n<<" "<<m;
		 else cout<<m<<" "<<1;
	}
	return 0;
}
