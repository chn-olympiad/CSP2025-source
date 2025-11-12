#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int cj=a[0],p;
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(a[i]==cj){
			p=i+1;
			break;
		}
	}
	int c,r;
	if(p%n!=0){
		c=p/n+1;
	}else{
		c=p/n;
	}
	cout<<c<<" ";
	if(c%2==1){
		if(p%n==0){
			r=n;
		}else{
			r=p%n;
		}
	}else{
		if(p%n==0){
			r=1;
		}else{
			r=n-p%n+1;
		}
	}
	cout<<r;
	return 0;
}
