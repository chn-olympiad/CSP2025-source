#include<iostream>
#include<stdio.h>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	int a[t];
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+t,cmp);
	int k;
	for(int i=0;i<t;i++){
		if(a[i]==r){
			k=i;
			break;
		}
	}
	int x=k/n+1;
	cout<<x<<' ';
	if(x%2==1){
		cout<<k-(x-1)*n+1;
	}
	else{
		cout<<n-(k-(x-1)*n);
	}
	return 0;
}