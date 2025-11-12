#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans,a1;
long long x;
long long c,r; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(m>10 and m<100){
		a1=m%10;m=m/10;
	}
	else if(m>=100){
		a1=m%100;m=m/100;
	}
	else cin>>a1;
	ans=1;
	for(long long i=1;i<=n*m-1;i++){
		cin>>x;
		if(x>a1){ans++;}
	}
    if(ans%n==0)c=ans/n;
    else c=ans/n+1;
    if(c%2==0){
    	r=c*n-ans+1;
    }else r=ans-(c-1)*n;
    cout<<c<<" "<<r;
	return 0;
}
