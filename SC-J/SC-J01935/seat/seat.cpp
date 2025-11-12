#include<bits/stdc++.h>
using namespace std;
int m,n,c=1,p;
int main(){
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	p=a[0];
	for(int i=0;i<m*n;i++){
		if(a[i]>p)	++c;
	}
	int x,y;
	for(int i=1;n*i-n<c;i++){
		x=i;
	}
	if(x%2==1){
		y=(c-x*n+n);
	}else if(x%2==0){
		y=(x*n-c);
	}
	cout<<x<<" "<<y;
	return 0;
}