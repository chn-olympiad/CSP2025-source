#include<bits/stdc++.h> 
using namespace std;
int a[105],n,m,c,r,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])num++;
	}
	c=num/n;
	if(num%n>0)c++;
	if(c%2==1){
		r=num%n;
		if(r==0)r=n;
	}
	else {
		r=n-num%n+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
