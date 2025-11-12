#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n;
	int m;
	int c;
	int r;
	cin>>n>>m;
	int a[105];
	if(n*m<=1){
		int c=1;
		int r=1;
		cout<<c<<r;
		
	}
	for(int i=0;i<=n*m;i++){
	
	cin>>a[i];	
			
	}
	sort(a[1],a[n*m]);
	if(a[1]%4==0) {
		int c=a[1]/4;
		if(a[1]%8>4){
		int r=1;}
		else{int r=4;
		}
		
		
	}
	 if(a[1]%4==1){
	 	int c=a[1]/4;
	 	if(c%2==0){
		int r=4;}
		else{int r=1;
		}
	 	
	 	
	 }
	 if(a[1]%4==2){
	 	int c=a[1]/4;
	 	if(c%2==0){
		int r=3;}
		else{int r=2;
		}
	}
	 if(a[1]%4==3){
	 	int c=a[1]/4;
	 	if(c%2==0){
		int r=2;}
		else{int r=3;
		}
	}
	 cout<<c<<r;
	 
	 
	 
	 
	 
	 
	
	return 0;
}
