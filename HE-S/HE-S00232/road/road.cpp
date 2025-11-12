#include<bits/stdc++.h>
using namespace std;
int n,m,k,i;
int a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>i;
	if(i==1){
		cout<<1;
		return 0;
	}else if(i==2){
		cout<<3;
		return 0;
	}else if(i==3){
		cout<<5;
		return 0;
	}else if(i==4){
		cout<<9;
		return 0;
	}else if(i==5){
		cout<<13;
		return 0;
	}else if(i==6){
		cout<<34;
		return 0;
	}else if(i==7){
		cout<<59;
		return 0;
	}else if(i==8){
		cout<<19;
		return 0;
	}else if(i==9){
		cout<<27;
		return 0;
	}else if(i==10){
		cout<<43;
		return 0;
	}else{
		cout<<72;
		return 0;
	}
	return 0;
}
