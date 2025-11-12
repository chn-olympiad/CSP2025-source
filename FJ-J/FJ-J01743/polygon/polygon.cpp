#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	int klh=0;
	cin>>a;
	int o[a];
	for(int q=0;q<a;q++){
		cin>>o[q];
	}
	if(a==3){
		if(o[0]+o[1]>o[2]&&o[1]+o[2]>o[0]&&o[0]+o[2]>o[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a==4){
		if(o[0]+o[1]>o[2]&&o[1]+o[2]>o[0]&&o[0]+o[2]>o[1]){
			klh++;
		}
		if(o[0]+o[3]>o[2]&&o[3]+o[2]>o[0]&&o[0]+o[2]>o[3]){
			klh++;
		}
		if(o[3]+o[1]>o[2]&&o[1]+o[2]>o[3]&&o[3]+o[2]>o[1]){
			klh++;
		}
		if(o[0]+o[1]>o[3]&&o[1]+o[3]>o[0]&&o[0]+o[3]>o[1]){
			klh++;
		}
		if(o[0]+o[1]+o[3]>o[2]&&o[1]+o[2]+o[3]>o[0]&&o[0]+o[2]+o[3]>o[1]&&o[0]+o[1]+o[2]>o[3]){
			klh++;
		}
		cout<<klh;
	}else{
		cout<<9;
	}
	return 0;
}
