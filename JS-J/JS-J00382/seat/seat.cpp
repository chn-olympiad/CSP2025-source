#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int scare[100];

bool pai(int a,int b){
	return a>b;
}

int half(int num,int l,int r){
	int mid=l+(r-l)/2;
	int midn=scare[mid];
	if(num>midn) return half(num,l,mid);
	if(num<midn) return half(num,mid+1,r);
	else return mid;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	int g;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>scare[i];
	}
	g=scare[0];
	sort(scare+0,scare+n*m,pai);
	int o=half(g,0,n*m-1)+1;
	int x=1;
	while(o-n>0){
		x++;
		o-=n;
	}
	if(x%2==0){
		o=n-o+1;	
	}
	cout<<x<<' '<<o<<endl;
	return 0;
}
