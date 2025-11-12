#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001],h,l,d=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> h >> l;
	for(int i=1;i<=h*l;i++){
		cin >> a[i];
	}
	d=a[1];
	int c=h*l;
	sort(a+1,a+h*l+1);
	for(int i=1;i<=l;i++){
	if(i%2!=0){
		for(int j=1;j<=h;j++){
			if(a[c]==d){
				cout << i << ' ' << j;
				return 0;	
				}
			c--;
			}
	}
	else {
	for(int z=h;z>=1;z--){
			if(a[c]==d){
				cout << i << ' ' << z;
				return 0;
			}
		c--;
	 }
}
}
	return 0;
}
