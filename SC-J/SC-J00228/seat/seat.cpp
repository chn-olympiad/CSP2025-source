#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105],m,n,ans,sum,r,c,k;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1);
	for(sum=1;sum<=n*m;sum++){
		if(a[sum]==ans){
			break;
		}
	}
	sum=n*m-sum+1;
	c=(sum-1)/n+1;
	k=sum%n;
	if(k==0)	k=n;
	if(c%2!=0){
		r=k;
	}else{
		r=n+1-k;
	}
	cout<<c<<' '<<r;
	return 0;
}