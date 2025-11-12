#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],x;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			x=n*m-i+1;
			break;
		}
	}
//	cout<<x<<"\n";
	if(x%n==0){
		if((x/n)%2==0){
			cout<<x/n<<" "<<1;
		}else{
			cout<<x/n<<" "<<n;
		}
	}else{
		int c=x/n+1;
		int r=x-(c-1)*n;
		if(c%2==0){
			cout<<c<<" "<<n-r+1;
		}else{
			cout<<c<<" "<<r;
		}
	}
	return 0;
}