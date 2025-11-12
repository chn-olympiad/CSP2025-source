#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	//freopen("seat.cpp","r",stdin);
	//freopen("seat.cpp","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+1+n*m);
	int w;
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=n*m-i+1;
			break;
		}
	}
	
	int x,y;
	if(w%n==0){
		x=w/n;
	}else{
		x=w/n+1; 
	}
	if(x%2!=0){
		cout<<x<<" "<<1+x%n;
	}else{
		cout<<x<<" "<<n-x%n;
	}
	
} 
