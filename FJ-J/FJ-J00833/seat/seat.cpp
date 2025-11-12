#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int n,m,q,x;
	int a[150]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	q=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==q){
			x=i;
		}
	}
	cout<<x/m+1<<" ";
	if((x/m+1)%2==0){
		cout<<n-x%n;
	}
	else{
		cout<<x%n+1;
	}
	return 0;
}
