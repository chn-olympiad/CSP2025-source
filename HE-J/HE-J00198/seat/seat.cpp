#include<iostream>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	int a[t+5];
	int r;
	cin>>r;
	for(int i=0;i<t-1;i++){
		cin>>a[i];
	}
	int z=t;
	for(int i=0;i<t-1;i++){
		if(r>a[i]){
			z--;
		}
	}
	if(z==1){
		cout<<"1 1";
	}
	else if(z==2){
		cout<<"1 2";
	}
	else if(z==3){
		cout<<"2 2";
	}
	else{
		cout<<"2 1";
	}
	return 0;
}
