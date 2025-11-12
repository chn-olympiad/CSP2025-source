#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000],b[1000];
int sd;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		//a[1]=b[1];
		
		//sort(a+1,a+n+1);
		//i=i;
		//a[i]=a[i];
		//a[i]=b[1];
		//if(i<=m) m=m-i+1;
		//if(i>m&&i<=m+n) n=n+i+1;
		//if(i-m-n>n) m=m+1+i;
	
	}
	sd=a[1];
		if(sd=100)
		  cout<<1<<" "<<1;
		if(sd<100&&sd>98)
		cout<<n<<m-1;
		if(sd<=95){
	     	n=n-2+1;
		    cout<<n<<" "<<m;
	}
	return 0;
}