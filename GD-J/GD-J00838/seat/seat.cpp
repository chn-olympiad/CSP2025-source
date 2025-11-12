#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k[20][20],a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ll z=a[1],numi;
	sort(a+1,a+(n*m)+1,greater<ll>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==z) numi=i;
	}
	z=numi;
	ll dj=(z-1)/n+1;
	ll lin=(z-1)%(2*n);
	ll di;
	if(lin<n) di=lin+1;
	else di=2*n-lin;
	cout<<dj<<" "<<di;
	return 0;
} 
