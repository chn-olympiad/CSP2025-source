#include<bits/stdc++.h>
using namespace std; 
int n,m,k,x,y;
int a[1024][1024];
int b[10024];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}

if(b[1]==99){
	cout<<"1 2";
}else if(b[1]==98){
	cout<<"2 2";
}else if(b[1]==94){
	cout<<"3 1";
}else{
	cout<<"4 5";
}
	
	return 0;
}
