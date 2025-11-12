#include<bits/stdc++.h> 
using namespace std;
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	int x=m*n;
	for(int i=1;i<=x;i++){
		cin>>c[i];	
	}
	int s=c[1];
	for(int i=1;i<=x;i++){
		for(int j=1;j<x-i;j++){
			if(c[j]<c[j+1]) swap(c[j],c[j+1]);
		}
	}
	for(int i=1;i<=x;i++){
		if(c[i]==s){
			s=i;
			break;
		}
	}
	int a,b;
	if(s%n!=0){
		b=s/n+1;
	}else{
		b=s/n;
	}
	if(b%2==1){
		if(s%n==0)a=n;
		else a=s%n;
	}else{
		if(s%n==0)a=1;
		else a=n-s%n+1;
	}
	cout<<b<<" "<<a;
	return 0;
}