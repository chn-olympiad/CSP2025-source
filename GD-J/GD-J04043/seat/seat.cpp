#include<bits/stdc++.h>
using namespace std;
int n,m,xr,t;
int a[200];
int x,y;
bool bo(int a,int b){
	return a>b;
}
bool ifj(int a){
	if(a%2==0){
		return false;
	}
	else return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++){
		cin>>a[i];
	}
	xr=a[0];
	sort(a,a+(n*m),bo);
	for(int i=0;i<(n*m);i++){
		if(a[i]==xr){
			t=i;
			break;
		}
	}
	if(ifj(t/n)){
		x=(t/n)+1;
		y=m-(t%n);
	}
	else{
		x=(t/n)+1;
		y=(t%n)+1;
	}
	cout<<x<<" "<<y;
	return 0;	
} 
