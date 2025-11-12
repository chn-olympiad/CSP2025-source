#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,a[105],p,r,c,k,id;
signed main(){
	IOS
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+1+n*m);
	k=lower_bound(a+1,a+1+n*m,p)-a;
	id=n*m-k+1;
	if(id%n==0) c=id/n;
	else c=id/n+1;
	if(c%2==1){
		if(id%n==0) r=n;
		else r=id%n;
	}
	else{
		if(id%n==0) r=1;
		else r=n-id%n+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
