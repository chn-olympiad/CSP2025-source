#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],s=0,k=0,c,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int j=0;j<n*m;j++){
		if(a[0]>a[j]){
			s++;
		}
		k++;
	}
	s=k-s;
	if(s%n==0){
		c=s/n;
	}
	else{
		c=s/n+1;
	}
	if(c%2==0){
		r=n-s%n+1;
	}
	else if(c==1){
		r=s;
	}
	else{
		r=s%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
