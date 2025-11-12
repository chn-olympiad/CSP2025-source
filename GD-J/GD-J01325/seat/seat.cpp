#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,c,r,sum=1,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
		    sum++;	
		}
	}
	int b=sum%n;
	if(b==0){
		c=sum/n;
	}
	else{
		c=sum/n+1;
	}
	if(c%2==1){
		if(b==0){
			r=n;
		}
		else{
			r=b;
		}
	}
	else{
		if(b==0){
			r=1;
		}
		else{
			r=n-b+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
