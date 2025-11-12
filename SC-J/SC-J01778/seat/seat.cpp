#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int now_;
int arr[105];
int dir;
bool f(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	now_=arr[0];
	sort(arr,arr+n*m,f);
	for(int i=0;i<n*m;i++){
		if(arr[i]==now_){
			dir=i;
			break;
		}
	}
	cout<<dir<<' ';
	cout<<dir/n+1<<' ';
	if((dir/n+1)%2==0){
		cout<<n-dir%3;
	}else{
		cout<<dir%n+1;
	}
	return 0;
}