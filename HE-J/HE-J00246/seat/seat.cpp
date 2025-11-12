#include<bits/stdc++.h>
using namespace std;
//行数 n 与列数 m
int n,m;
int a[222];
bool cmp(int a,int b){
	return a>b;
}
void print_seat(int k){
	int x,y;
	if(k%n==0){
		x=k/n;
	}else{
		x=k/n+1;
	}
	
	
	if(k%n==0){
		y=n;
	}else{
		y=k%n;
	}
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y<<'\n';
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int r=0;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		} 
	}
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==r){
			print_seat(i);
			break;
		}
		
	}
	return 0;
}
