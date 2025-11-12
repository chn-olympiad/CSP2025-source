#include<bits/stdc++.h>
using namespace std;
int x,y,a,m=1,ai;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y>>a;
	for(int i=1;i<x*y;i++){
		cin>>ai;
		if(ai>a){
			m++;
		}
	}
	if(m%x==0){
		cout<<m/x;
		if((m/x)%2==0){
			cout<<" "<<1;
		}else cout<<" "<<x;
		
	}else{
		cout<<m/x+1;
		if((m/x+1)%2==0){
			cout<<" "<<x-(m%x)+1;
		}else cout<<" "<<m%x;
	}
	fclose(stdin);
	fclose(stdout);
}
 
