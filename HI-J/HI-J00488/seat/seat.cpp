#include<bits/stdc++.h>
using namespace std;
int n,m,c,r=0,t,f=1;
long long int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			f+=1;
		}
	}
	r=f/n;
	if(f%n!=0){
		r+=1;
	}
	t=f-1;
	cout<<r<<' ';
	if(r%2==1){
		t%=n;
		cout<<1+t;
	}
	if(r%2==0){
		t%=n;
		cout<<n-t;
	}
	return 0;
} 
