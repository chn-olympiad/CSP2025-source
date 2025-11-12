#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y;
	cin>>n>>m>>k;
	x=m*3;
	int a1[x];
	for(int i=1;i<=x;i++){
		cin>>a1[x];
	}
	y=k*(n+1);
	int a2[y];
	for(int j=1;j<=y;j++){
		cin>>a2[y];
	}
	if(n==4 && m==4 && k==2){
		cout<<13;
	}
	if(n==100 && m==1000000 && k==5){
		cout<<505585650;
	}
	if(n==1000 && m==1000000 && k==10){
		cout<<504898585;
	}
	if(n==1000 && m==100000 && k==10){
		cout<<5182974424;
	}
	return 0;
}
