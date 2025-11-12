#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[i]<a[j]){
				int x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	int x=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==R){
			x=i+1;
			break;
		}
	}
	int c,r;
	if(x%n==0){
		c=x/n;
		if(c%2==1){
			r=n;
		}
		else{
			r=1;
		}
	}
	else{
		c=x/n+1;
		if(c%2==1){
			r=x%n;
		}
		else{
			r=n-x%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

