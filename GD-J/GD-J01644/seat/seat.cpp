#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	int n,m,c,r,x;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+m*n+1,cmp);
	c=(x-1)/n+1;
	if(c%2==0)
		r=c*n+1-x;
	else
		r=(x-1)%n+1;
	cout<<c<<" "<<r;
	return 0;
}
 
