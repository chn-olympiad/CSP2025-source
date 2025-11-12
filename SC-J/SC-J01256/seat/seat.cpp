#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int d=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			d++;
		}
	}
	int xn=1;
	int i=1,j=1;
	for(;;){
		if(xn==d){
			cout<<j<<' '<<i;
			return 0;
		}
		if(j%2){
			if(i==n){
				j++;
			}else{
				i++;
			}
		}else{
			if(i==1){
				j++;
			}else{
				i--;
			}
		}
		xn++;
	}
	return 0;
}