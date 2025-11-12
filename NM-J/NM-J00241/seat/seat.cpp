#include<bits/stdc++.h>
using namespace std;
bool fc(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	if(n<=1&&m<=1){
		cout<<"1 1";
		return 0;
	}
	long long x=n*m;
	long long a[200]={};
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	long long y=a[0];
	
//	for(int i=0;i<x;i++){
//		cout<<a[i]<<" ";
//	}
	sort(a,a+x,fc);
	for(int i=0;i<x;i++){
		if(a[i]==y){
			y=i+1;
		}
	}
	if(n==1&&m==2){
		if(y==1)cout<<"1 1";
		else cout<<"1 2";
	}else if(n==2&&m==1){
		if(y==1)cout<<"1 1";
		else cout<<"2 1";
	}else if(y==1){
		cout<<"1 1";
	}else if(y==x){
		if(y%n==0){
			cout<<n<<" "<<m;
		}else {
			int g=x/n;
			cout<<g+1<<" "<<y%n;
		}
	}
	return 0;
}
