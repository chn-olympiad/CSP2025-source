#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m,r,c=1,k; 
	cin>>n>>m>>r;
	int a[n*m-1];
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i]; 
		if(r<a[i]){
			c++;
		}
	}
	if(c>m&&c%m==0){
		k=c/m;
		cout<<c/m<<' ';
	}
	if(c>m&&c%m!=0){
		k=c/m+1;
		cout<<c/m+1<<' ';
	}
	else{
		cout<<1<<' ';
	}
	if(c>m&&k%2==0&&c%m!=0){
		cout<<n-(c%((k-1)*n)-1)<<' ';
	}
	else if(c>m&&k%2==1){
		cout<<c%k<<' ';
	}
	else{
		cout<<c<<' ';
	}
	return 0;
}

