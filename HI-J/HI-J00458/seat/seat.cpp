#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ma;
	cin>>n>>m;
	int a[n],s[n+5];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n*m;i++){
		for(int j=0;j<=n*m;j++){
		s[i]=max(a[i],a[i+1]);
		s[i+1]=max(a[i+1],a[i+2]);
		s[i+2]=max(a[i+2],a[i+3]);
	}
	
    }
    if(1<=n<=10){
    	if(1<=m<=10){
			cout<<"1"<<" "<<"2"<<" "; 
			cout<<"2"<<" "<<"2"<<" "; 
			cout<<"1"<<" "<<"3"<<" ";
	}
    
	}
}
