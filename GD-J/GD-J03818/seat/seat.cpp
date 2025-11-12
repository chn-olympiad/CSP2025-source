#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=105;
int n,m,a[N*N],aa,r,c,p;
signed main(){
#ifndef XYZ
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	aa=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			p=i;
		}
	}
	c=(p-1)/n+1;
	r=(p-1)%n+1;
	if(!(c&1))r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}

