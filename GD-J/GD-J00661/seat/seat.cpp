#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=0,y=0,cj[100],n=0,a=0,ansx,ansy;
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>cj[i];
	}
	for(int i=100;i>=1;i--){
		for(int j=0;j<x*y;j++){
			if(cj[j]==i){
				n++;
				if(j==0){
					a=1;
					break;
				}
			}
		}
		if(a==1)break;
	}
	ansx=n/y;
	if(ansx%2==0){
		if(n%y!=0){
			ansy=n%y;
			ansx++;
		}
		if(n%y==0)ansy=1;
	}
	else{
		if(n%y!=0){
			ansy=y-(n%y);
			ansx++;
		}
		if(n%y==0)ansy=y;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
} 
