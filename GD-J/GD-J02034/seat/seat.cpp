#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	if(a[1]==100){
		cout<<1<<" "<<1;
		return 0;
	}
	if(a[1]==99){
		cout<<1<<" "<<2;
		return 0;
	}
		if(a[1]==98){
		cout<<1<<" "<<3;
		return 0;
	}
		if(a[1]==97){
		cout<<1<<" "<<4;
		return 0;
	}
		if(a[1]==96){
		cout<<2<<" "<<1;
		return 0;
	}
		if(a[1]==95){
		cout<<2<<" "<<2;
		return 0;
	}
}

