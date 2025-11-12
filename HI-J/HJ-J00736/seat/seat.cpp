#include<bits/stdc++.h>
using namespace std;
int yx[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	 if(h*l==1){
	 	cout<<1<<' '<<1;
	 	
	 }else{
	 
	 int cj,all=0;
	 for(int a=0;a<h*l;a++){
	 	cin>>yx[a]; 
	 	if(a==0){
	 	cj=yx[a];	
		 }
		 if(yx[a]>cj){
		 	all++;
		 }
	 }
	 int pm=all+1;
	if(pm<=h){
		cout<<1<<' '<<pm; 
	} else{
		cout<<(pm/h)+1<<' ';
		if(((pm/h)+1)%2==0){
			cout<<h-(pm%h)+1;
		}else{
			cout<<pm%h;
		}
	}
}
	return 0;
}

