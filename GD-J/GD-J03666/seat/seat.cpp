#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m;
	cin>>n>>m;
	int q,p,c,r,k=n*m;
	int a[n];
	int i;
	for(i=1;i<=k;i++){
		cin>>a[i];
		if(i==1){
			q=a[i];
		}
	}
	sort(a+1,a+k+1);
	for(i=1;i<=k;i++){
		if(a[i]==q){
			p=k-i+1;
			break;
		}
	}
	if(p%n==0&&(p/n)%2==1){
		r=n;
	}
	else if(p%n==0&&(p/n)%2==0){
		r=1;
	}
	else if((p/n)%2==1){
		r=n-p%n+1;
	}
	else{
		r=p%n;
	}
	if(p%n!=0){
		c=p/n+1;
	}
	else{
		c=p/n;
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}
