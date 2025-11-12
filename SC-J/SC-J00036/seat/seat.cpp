#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,y,z,d;
int b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+z+1);
	for(int i=1;i<=z;i++){
		if(a[i]==x){
			y=z-i+1;
		}
	}
    b=y/n;
    d=y%n;
    if(d!=0){
    	b++;
	}
    if(b<y/n){
    	b++;
	}
    if(b%2==1){
    	c=y%n;
    	if(c==0){
    		c=n;
		}
	}else{
		c=n-y%n+1;
		if(y%n==0){
			c=1;
		}
	}
	cout<<b<<" "<<c;
	return 0;
} 