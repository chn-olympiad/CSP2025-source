#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a,b,h=1,l=1,x=0;
	int c[a*b],d[a][b];	
	cin>>a>>b;
	for(int i=1;i<=a;i++){
			cin>>c[i]; 
	}	
	for(int i=1;i<=a*b;i++){
		if(d[1]>d[i]){
			x=x+1;
		}
	}if(x>=a+1){
		l+=0;
		h+=1;
	}else{
		h+=0;
		l+=0;
	}if(x>=b+1){
		l+=1;
		h+=0;
	}else{
		h+=1;
		l+=0;
	}cout<<l<<" "<<h;
	return 0;
}
