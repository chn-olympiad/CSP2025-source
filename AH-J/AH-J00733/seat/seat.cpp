#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int h;
int s=1;
int p,q;
int a[1010]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	h=n*m;
	cin>>a[0];
	for(int i=1;i<h;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			s++;
		}
	}
	p=s/n;
	q=s%n;
	if(q>0 && q<n){
		p++;
	}
	if(q==0){
		q=n;
	}
	if(p%2!=0){
		cout<<p<<" "<<q;
	}else{
		cout<<p<<" "<<n-q+1;
	}
	return 0;
}
