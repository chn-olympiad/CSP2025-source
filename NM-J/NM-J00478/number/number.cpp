#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	int x=0,y[1000000];
	for(int i=1;i<=1000000;i++){
		cin>>a[i];
		if(a[i]>=0 && a[i]<=9){
			if(a[i]>=x){
				y[i]=a[i];
			}
		}
	}
	for(int i=1;i<=100000;i++){
		if(y[i]>y[i+1]){
			x=y[i];
			y[i]=y[i+1];
			y[i+1]=x;
		}
	}
	for(int i=1;i<=1000000;i++){
		cout<<y[i];
	}
	return 0;
}
