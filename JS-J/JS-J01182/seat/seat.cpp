#include<bits/stdc++.h>
using namespace std;
string s;
long long a[2000];
long long l,b,c,n,m,r,rs;
long long x2,y2;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>> n >> m;
	cin>> a[1];
	r=a[1];
	b=n*m;
	for(long long i=2;i<=b;i++){
		cin>> a[i];
	}
	sort(a+1,a+1+b,cmp);
	for(long long i=1;i<=b;i++){
		if(r==a[i]){
			rs=i;
			break;
		}
	}
	if(rs%n==0){
		y2=rs/n;
	}
	else{
		y2=rs/n+1;
	}
	if(y2%2==1){
		if(rs%n==0){
			x2=n;
		}
		else{
			x2=rs%n;
		}	
	}
	else{
		if(rs%n==0){
			x2=1;
		}
		else{
			x2=n-rs%n+1;
		}
	}
	cout<< y2 << ' ' << x2 << "\n";
	return 0;
}
