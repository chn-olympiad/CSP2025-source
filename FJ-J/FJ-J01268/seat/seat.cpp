#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c,r,sum=1;
	cin>>n>>m;
	int a[105];
	cin>>a[1];
	for(int i=2;i<=m*n;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	c=ceil((double)sum/(double)n);
	if(c%2==0){
		if(sum%n==0){
			r=1;
		}else{
			r=n-(sum%n)+1;
		}
	}else{
		if(sum%n==0){
			r=n;
		}else{
			r=sum%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
