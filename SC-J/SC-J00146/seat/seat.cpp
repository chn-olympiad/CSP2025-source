#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500],c,r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long k=a[1],l;
	sort(a+1,a+n*m+1);
	for(long long i=n*m;i>=1;i--){
		if(a[i]==k){
			l=n*m+1-i;
			break;
		}
	}
	if(l/n==0){
		c=1;
		r=l;
	}else if(l/n!=0&&l%n==0){
		c=l/n;
		r=n;
	}else if(l/n!=0&&l%n!=0){
		c=l/n+1;
		if(c%2==0){
			r=n+1-l%n;
		}else{
			r=l%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}