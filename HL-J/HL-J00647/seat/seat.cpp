#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int front=1;
	int R;
	cin>>R;
	for(int i=0;i<n*m-1;i++){
		int ste;
		cin>>ste;
		if(ste>R){
			front++;
		}
	}
	int l,h;
	if(front%n==0){
		l=front/n;
	}else{
		l=front/n+1;
	}
	if(front<=n){
		h=front;
	}else if((front/n)%2==1){
		h=n-front%n+1;
	}else if((front/n)%2==0){
		h=front%n;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
