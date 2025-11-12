#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m;
	int x,y;
	cin>>n>>m;
	int num,num1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			num=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			num1=n*m-i+1;
		}
	}
	if(num1%n==0){
		x=num1/n;
		if(x%2==1){
			y=n;
		}else{
			y=1;
		}
	}else{
		x=num1/n+1;
		if(x%2==1){
			y=num1%n;
		}else{
			y=n-num1%n+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
