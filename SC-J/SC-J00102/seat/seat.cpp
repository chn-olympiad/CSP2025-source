#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1001],rk=1,h,l;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++)rk+=(a[i]>a[1]);
	h=(rk-1)/n+1;
	if(h%2)l=(rk-1)%n+1;
	else l=n+1-(rk-1)%n-1;
	cout<<h<<' '<<l;
	return 0;
}