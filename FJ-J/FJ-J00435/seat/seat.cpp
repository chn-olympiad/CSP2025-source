#include <iostream>
using namespace std;
int n,m,x,a,sum=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>a){
			sum++;
		}
	}
	if(sum%n==0){
		r=n;
		c=sum/n;
	}
	else{
		r=sum%n;
		c=sum/n+1;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
}
