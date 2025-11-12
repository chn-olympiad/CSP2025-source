#include<bits/stdc++.h>
using namespace std;
int n,m,Mark[105],c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>Mark[i];
	}
	int R_mark=Mark[1]; 
	
	sort(Mark+1,Mark+1+nm,cmp); 
	int pm=0;
	
	for(int i=1;i<=nm;i++){
		if(Mark[i]==R_mark){
			pm=i;
		}
	}
	c=pm/n+1;
	r=pm%n;
	if(r==0){
		c=c-1;
	}
	if(c%2==0){
		if(r!=0) r=n-r+1;
		else r=1; 
	}
	else if(c%2==1){
		if(r==0) r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
