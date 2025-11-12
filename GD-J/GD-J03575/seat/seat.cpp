#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,ar;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ar;
	int cnt=0;
	for(int i=2,a;i<=n*m;i++){
		cin>>a;
		if(a>ar) cnt++;
	}
	int r=1,c=1;
	bool isdown=true;
	while(cnt>0){
		if(isdown) r++;
		else r--;
		if(r>n) r=n,c++,isdown=false;
		if(r<1) r=1,c++,isdown=true;
		cnt--;
	}
	cout<<c<<' '<<r<<endl;
	return 0;
} 
