#include <iostream>
using namespace std;
int d[19207963],a[19207965],x,y;
int main({
	cin >>x >> y;
	for(int i=0;i <x*y;i++){
		cin >> a[i];
	}
	int max=a[0];
	int b = a[0];
	a[0]=-1; 

	int c;
	for(int i = 0;i<x*y;i++ ){
		for(int j = 0;j < x*y;j++){
			if(a[j]>max){
				max =c;
				max = a[j];
				a[j] = max;
			}
		}
		d[i]= max;
		max =-1;
	}
	c = 1;
	for(int i =0;i <x*y;i++){
		if(d[i]==b){
			break;
		}
		c += 1;
	}
	if((c%y)==0){
		if((((c/y)+1)%2)==1){
			cout <<c/y<<y;
		}
		else{cout <<c/y<<1;
		}
	}
	else{
		if((((c/y)+1)%2)==1){
			cout <<((c/y)+1)<<c%y;
		}
		else{cout <<c/y<<','<<(y-(c%y));
		}
	}
}
