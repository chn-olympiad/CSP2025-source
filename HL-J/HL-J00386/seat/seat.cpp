#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,r,t=0;
	cin>>h>>l;
	int a[10001];
	for(int i=0;i<h*l;i++){
		cin>>a[i];
	}
	r=a[0];
	for(int i=0;i<h*l-1;i++){
		for(int k=0;k<h*l-1-i;k++){
			if(a[k]<a[k+1]){
				swap(a[k],a[k+1]);
			}
		}
	}
	for(int i=0;i<h*l;i++){
		if(a[t]==r){
			break;
		}
		else{
			t++;
		}
	}
	t++;
	
	
	
	
	if(t%h==0){
		cout<<t/h<<" ";
		if(t/h%2==0){
		cout<<1;
		}
		if(t/h%2!=0){
			cout<<h;
		}
	}
	else{
		cout<<t/h+1<<" ";
		if((t/h+1)%2==0){
		cout<<h-(t%h)+1;
		}
		if((t/h+1)%2!=0){
			cout<<t%h;
		}
	}
	return 0;
}
