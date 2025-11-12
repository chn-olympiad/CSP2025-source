#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			r=i;
			break;
		}
	}
	cout<<(n*m-r)/n+1<<" ";
	if((n*m-r+1)%n==0){
		cout<<n;
	}
	else{
		if(((n*m-r)/n+1)%2==1)cout<<(n*m-r+1)%n;
		else cout<<n-(n*m-r+1)%n+1;
	}
	return 0;
}
