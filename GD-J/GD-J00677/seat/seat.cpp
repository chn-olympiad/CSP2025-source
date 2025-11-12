#include<iostream>
#include<cstring>
using namespace std;
int main(){
    fropen("seat.in","r",strin);
    fropen("seat.out","w",strout);
    int a[1005];
	int n=0,m=0,R=0,x=1,y=0,k;
	cin>>n>>m;
	cin>>R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>R){
			x+=1;
		}
	}
	y=x/n+(x%n);
	x=x%n;
	if(y%2==1){
		cout<<y<<" "<<x;
	}	
	else{
		x=(n+1)-x;
		cout<<y<<" "<<x;
	}
    return 0;
} 
