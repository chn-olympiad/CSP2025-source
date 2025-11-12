#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	int q=n*m;
	int a[105];
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+q+1);
	for(int i=q;i>=1;i--){
		if(p==a[i]){
			z=q-i+1;
			break;
		}
	}
	int x,y;
	if(z%n==0) {
		x=z/n;
	}
	else if(z%n>0){
		x=z/n+1;
	}
	
	if(x%2!=0){
		if(z%n==0) y=n;
		else if(z%n!=0){
			y=z%n;
		}
	}
	else if(x%2==0){
		if(z%n==0) y=1;
		else if(z%n!=0){
			y=n-z%n+1;
		}
	}
	cout<<x<<" "<<y<<" ";
	return 0;
} 