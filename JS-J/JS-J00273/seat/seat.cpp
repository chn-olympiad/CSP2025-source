#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[101],q,p,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	q=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(q==a[i]){
			p=i;
			break;
		}
	}
	p=n*m-p+1;
	if(p%n) x=p/n+1;
	else x=p/n;
	y=(p-1)%n+1;
	if(x%2==0) y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
}
