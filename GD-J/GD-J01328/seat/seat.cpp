#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long x;
long long y;
long long a[1001];
long long h;
long long l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==x){
			y=n*m-i+1;
			break;
		}
	}
	if(y%n==0){
		l=y/n;
	}else{
		l=y/n+1;
	}
	if(y%(2*n)<=n&&y%(2*n)!=0){
		h=y%(2*n);
	}else{
		if(y%(2*n)==0){
			h=1;
		}else{
			h=(2*n)-y%(2*n)+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
