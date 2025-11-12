#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
int x,y,a[105][105];
int b[105][105];
cin>>x>>y;
for(int i=0;i<x;i++){
for(int j=0;j<y;j++){
	cin>>a[i][j];
}
}
int r=a[1][1];
for(int i=1;i<=x;i++){	
	if(i%2!=0){
	for(int j=1;j<=y;j++){
	     b[i][j]=a[i][j];
	}
	}
	else if(i%2==0){
		for(int j=1;j>=1;j--){
	     b[i][j]=a[i][j];
	}
	}
}
for(int i=1;i<=x;i++){
	for(int j=1;j<=y;j++){
	if(b[i][j]==r){
		cout<<i<<" "<<j;
	}
}
}
return 0;
}
