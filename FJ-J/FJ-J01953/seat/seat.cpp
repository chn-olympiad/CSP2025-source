#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[1005],m,n;
bool k(int m,int n){
	return m>n;
}
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+m*n+1,k);
	double y2;
	for(int i=1;i<=m*n;i++){
		if(a[i]==x){
		 	y2=i;
			 break; 
		}
	} 
	int y=int(y2);
	int mm=ceil(y2/n);
	int nn;
	if(mm%2==1){
		if(y%n==0){
			nn=n;
		}
		else nn=y%n;
	}
	else if(mm%2==0){
		if(y%n==0){
			nn=1; 
		}
		else nn=n-y%n+1;
	 } 
	 cout<<mm<<' '<<nn;
	return 0;
} 
