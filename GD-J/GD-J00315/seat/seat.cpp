#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a,num=1,c,r;
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>a1)num++;
	}
	c=num/n;
	if(num%n!=0)c++;
	if(c%2==1){
		r=num%n;
		if(r==0)r=n;
	}
	else{
		r=n-num%n+1;
		if(r>n)r%=n;
	}
	cout<<c<<" "<<r; 
	return 0;
}
