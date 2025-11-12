#include <iostream>
#include <cmath>
using namespace std;

int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	int s;
	cin>>s;
	if(abs(s)<=1){
		cout<<max(s);		
	}
	if(abs(s)<=2){
		cout<<max(s);
	}
	if(abs(s)<=10){
		cout<<max(s);
	}
	if(abs(s)<=10^2){
		cout<<max(s);
	}
	if(abs(s)<=10^3){
		cout<<max(s);
	}
	if(abs(s)<=10^5){
		cout<<max(s);
	}
	if(abs(s)<=10^6){
		cout<<max(s);
	}
	return 0;
}
