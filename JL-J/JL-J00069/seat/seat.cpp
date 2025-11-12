#include<bits/stdc++.h>
using namespace std;
long long a[100];
bool tmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,pai;
	cin>>n>>m;
	for(long long i=0;i<m*n;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+m*n,tmp);
	for(long long i=0;i<m*n;i++){
		if(a[i]==r){
			pai=i+1;
		}
	}
	int x=pai/n,y;
	if(x*n!=pai){
		x++;
	}
	cout<<x<<" ";
	if(x%2!=0){
		y=pai%n;
		if(y==0){
			cout<<n;
		}
		else{
			cout<<y;
		}
	}
	else{
		y=n+1-pai%n;
		cout<<y;
	}
	return 0;
}
