#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,m,w,h,l;
int a[101],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int v=m*n;
	for(int i=1;i<=v;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];  
		}
	}
	sort(a+1,a+v+1,cmp);
	for(int i=1;i<=v;i++){
		if(a[i]==x){
			w = i;
		}
	}
	if(w%n==0){
		l = w/n;
	}else{
		l = w/n+1;
	}
	if(l%2==1){
		if(w%n==0){
			h = n;
		}else{
			h = w%n;
		}
	}else{
		if(w%n==0){
			h =1;
		}else{
			h = n - w%n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}