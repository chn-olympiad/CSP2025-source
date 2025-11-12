#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m],xia[n*m];
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
		xia[i]=i;
	}
	int x=n*m;
	for(int i=0;i<x;i++){
		for(int j=0;j<x-1-i;j++){
			if(arr[j]<arr[j+1]){
				swap(arr[j],arr[j+1]);
				swap(xia[j],xia[j+1]);
			}
		}
	}
	int c=0,r=0,num=0;
	for(int i=0;i<x;i++){
		if(xia[i]==0){
			num=i+1;
			break;
		}
	}
	if(num<=n){
		c=1;
		r=num;
		cout<<c<<" "<<r;
		return 0;
	}
	else{
		c=num/n+1;
		if(c%2==1){
			r=num%n;
		}
		else if(c%2==0){
			r=n-num%n+1;
		}
		cout<<c<<" "<<r;
	}
	return 0;
}
