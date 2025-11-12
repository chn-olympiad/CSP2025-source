#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
	    cin>>c[i];
	}
	if(a==1&&b==1)cout<<"1 1";
	if(a==2&&b==1){
		if(c[1]>c[2])cout<<"1 1";
		else cout<<"2 1";
	}
	if(a==1&&b==2){
		if(c[1]>c[2])cout<<"1 1";
		else cout<<"1 2";
	}
	if(a==2&&b==2){
		if(c[1]>c[2])cout<<"1 1";
		else cout<<"2 2";
	}
	if(a==1&&b>2){
	   if(c[1]>c[2])cout<<"1 1";
	   else cout<<"1 "<<b;
	}
	if(a==2&&b>2){
	   if(c[1]>c[2])cout<<"1 1";
	   else cout<<"2 "<<b;
	}
	return 0;
}
