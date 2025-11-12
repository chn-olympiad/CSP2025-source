#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,a,r,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>r){
			num++;
		}
	}
	cout<<int(ceil(num*1.0/n))<<' ';
	if(int(ceil(num*1.0/n))%2 ==1){
		if(num%n){
			cout<<num%n;
		}
		else{
			cout<<n;
		}
	}
	else{
		if(num%n){
			cout<<n-(num%n)+1;
		}
		else{
			cout<<n-(n)+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}