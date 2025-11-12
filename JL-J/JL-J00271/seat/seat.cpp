#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1009],s,r,x;
bool c(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,c);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			r=i;
		}
	}
	if(r%n!=0){
		x=r/n+1;
		if(x%2==1){
			cout<<x<<" "<<r%n;
		}else{
			cout<<x<<" "<<n-r%n+1;
		}
	}else{
		x=r/n;
		if(x%2==1){
			cout<<x<<" "<<n;
		}else{
			cout<<x<<" "<<1;
		}
	}
	return 0;
}
