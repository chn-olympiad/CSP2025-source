#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a,b;
	int w=0;
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a){
			w++;
		}
	}
	int l=(w+1)/n+1;
	int h=(w+1)%n;  
	if(h==0){
		if(l%2==0){
			cout<<l-1<<" "<<n;
		} 
		else{
			cout<<l-1<<" "<<1;
		}
	}
	else if(l%2==1){
		cout<<l<<" "<<h;
	}
	else{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
} 