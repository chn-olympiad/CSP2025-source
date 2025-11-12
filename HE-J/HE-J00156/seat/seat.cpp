#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,x=0;
int a[100]; 
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=100;i++){
		if(a[i]>x){
			x=a[i];
			a[2]=x;
		}
		cout<<"1"<<" "<<x;	
	}
	if(x<=n){
		cout<<"1"<<" "<<x;
	}
	return 0;
}
